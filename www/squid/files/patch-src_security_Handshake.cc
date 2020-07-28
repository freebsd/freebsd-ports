--- src/security/Handshake.cc.orig	2020-06-07 15:42:16 UTC
+++ src/security/Handshake.cc
@@ -9,6 +9,7 @@
 /* DEBUG: section 83    SSL-Bump Server/Peer negotiation */
 
 #include "squid.h"
+#include "sbuf/Stream.h"
 #include "security/Handshake.h"
 #if USE_OPENSSL
 #include "ssl/support.h"
@@ -104,25 +105,52 @@ class Extension (public)
 typedef std::unordered_set<Extension::Type> Extensions;
 static Extensions SupportedExtensions();
 
-} // namespace Security
-
 /// parse TLS ProtocolVersion (uint16) and convert it to AnyP::ProtocolVersion
+/// \retval PROTO_NONE for unsupported values (in relaxed mode)
 static AnyP::ProtocolVersion
-ParseProtocolVersion(Parser::BinaryTokenizer &tk, const char *contextLabel = ".version")
+ParseProtocolVersionBase(Parser::BinaryTokenizer &tk, const char *contextLabel, const bool beStrict)
 {
     Parser::BinaryTokenizerContext context(tk, contextLabel);
     uint8_t vMajor = tk.uint8(".major");
     uint8_t vMinor = tk.uint8(".minor");
+
     if (vMajor == 0 && vMinor == 2)
         return AnyP::ProtocolVersion(AnyP::PROTO_SSL, 2, 0);
 
-    Must(vMajor == 3);
-    if (vMinor == 0)
-        return AnyP::ProtocolVersion(AnyP::PROTO_SSL, 3, 0);
+    if (vMajor == 3) {
+        if (vMinor == 0)
+            return AnyP::ProtocolVersion(AnyP::PROTO_SSL, 3, 0);
+        return AnyP::ProtocolVersion(AnyP::PROTO_TLS, 1, (vMinor - 1));
+    }
 
-    return AnyP::ProtocolVersion(AnyP::PROTO_TLS, 1, (vMinor - 1));
+    /* handle unsupported versions */
+
+    const uint16_t vRaw = (vMajor << 8) | vMinor;
+    debugs(83, 7, "unsupported: " << asHex(vRaw));
+    if (beStrict)
+        throw TextException(ToSBuf("unsupported TLS version: ", asHex(vRaw)), Here());
+    // else hide unsupported version details from the caller behind PROTO_NONE
+    return AnyP::ProtocolVersion();
 }
 
+/// parse a framing-related TLS ProtocolVersion
+/// \returns a supported SSL or TLS Anyp::ProtocolVersion, never PROTO_NONE
+static AnyP::ProtocolVersion
+ParseProtocolVersion(Parser::BinaryTokenizer &tk)
+{
+    return ParseProtocolVersionBase(tk, ".version", true);
+}
+
+/// parse a framing-unrelated TLS ProtocolVersion
+/// \retval PROTO_NONE for unsupported values
+static AnyP::ProtocolVersion
+ParseOptionalProtocolVersion(Parser::BinaryTokenizer &tk, const char *contextLabel)
+{
+    return ParseProtocolVersionBase(tk, contextLabel, false);
+}
+
+} // namespace Security
+
 Security::TLSPlaintext::TLSPlaintext(Parser::BinaryTokenizer &tk)
 {
     Parser::BinaryTokenizerContext context(tk, "TLSPlaintext");
@@ -431,6 +459,8 @@ Security::HandshakeParser::parseExtensions(const SBuf 
             break;
         case 16: { // Application-Layer Protocol Negotiation Extension, RFC 7301
             Parser::BinaryTokenizer tkAPN(extension.data);
+            // Store the entire protocol list, including unsupported-by-Squid
+            // values (if any). We have to use all when peeking at the server.
             details->tlsAppLayerProtoNeg = tkAPN.pstring16("APN");
             break;
         }
@@ -441,8 +471,9 @@ Security::HandshakeParser::parseExtensions(const SBuf 
         case 43: // supported_versions extension; RFC 8446
             parseSupportedVersionsExtension(extension.data);
             break;
-        case 13172: // Next Protocol Negotiation Extension (expired draft?)
         default:
+            // other extensions, including those that Squid does not support, do
+            // not require special handling here, but see unsupportedExtensions
             break;
         }
     }
@@ -455,7 +486,7 @@ Security::HandshakeParser::parseCiphers(const SBuf &ra
     Parser::BinaryTokenizer tk(raw);
     while (!tk.atEnd()) {
         const uint16_t cipher = tk.uint16("cipher");
-        details->ciphers.insert(cipher);
+        details->ciphers.insert(cipher); // including Squid-unsupported ones
     }
 }
 
@@ -473,7 +504,7 @@ Security::HandshakeParser::parseV23Ciphers(const SBuf 
         const uint8_t prefix = tk.uint8("prefix");
         const uint16_t cipher = tk.uint16("cipher");
         if (prefix == 0)
-            details->ciphers.insert(cipher);
+            details->ciphers.insert(cipher); // including Squid-unsupported ones
     }
 }
 
@@ -486,6 +517,7 @@ Security::HandshakeParser::parseServerHelloHandshakeMe
     details->tlsSupportedVersion = ParseProtocolVersion(tk);
     tk.skip(HelloRandomSize, ".random");
     details->sessionId = tk.pstring8(".session_id");
+    // cipherSuite may be unsupported by a peeking Squid
     details->ciphers.insert(tk.uint16(".cipher_suite"));
     details->compressionSupported = tk.uint8(".compression_method") != 0; // not null
     if (!tk.atEnd()) // extensions present
@@ -554,12 +586,15 @@ Security::HandshakeParser::parseSupportedVersionsExten
         Parser::BinaryTokenizer tkList(extensionData);
         Parser::BinaryTokenizer tkVersions(tkList.pstring8("SupportedVersions"));
         while (!tkVersions.atEnd()) {
-            const auto version = ParseProtocolVersion(tkVersions, "supported_version");
+            const auto version = ParseOptionalProtocolVersion(tkVersions, "supported_version");
+            // ignore values unsupported by Squid,represented by a falsy version
+            if (!version)
+                continue;
             if (!supportedVersionMax || TlsVersionEarlierThan(supportedVersionMax, version))
                 supportedVersionMax = version;
         }
 
-        // ignore empty supported_versions
+        // ignore empty and ignored-values-only supported_versions
         if (!supportedVersionMax)
             return;
 
@@ -569,7 +604,11 @@ Security::HandshakeParser::parseSupportedVersionsExten
     } else {
         assert(messageSource == fromServer);
         Parser::BinaryTokenizer tkVersion(extensionData);
-        const auto version = ParseProtocolVersion(tkVersion, "selected_version");
+        const auto version = ParseOptionalProtocolVersion(tkVersion, "selected_version");
+        // Ignore values unsupported by Squid. There should not be any until we
+        // start seeing TLS v2+, but they do not affect TLS framing anyway.
+        if (!version)
+            return;
         // RFC 8446 Section 4.2.1:
         // A server which negotiates a version of TLS prior to TLS 1.3 [...]
         // MUST NOT send the "supported_versions" extension.
