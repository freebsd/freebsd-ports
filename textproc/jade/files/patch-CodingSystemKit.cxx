--- lib/CodingSystemKit.cxx.orig	Sat Jul 31 17:03:29 2004
+++ lib/CodingSystemKit.cxx	Sat Jul 31 17:08:59 2004
@@ -74,7 +74,8 @@
     iso8859_6,
     iso8859_7,
     iso8859_8,
-    iso8859_9
+    iso8859_9,
+    koi8_r
   };
   struct Entry {
     const char *name;
@@ -111,6 +112,7 @@
   TranslateCodingSystem iso8859_7CodingSystem_;
   TranslateCodingSystem iso8859_8CodingSystem_;
   TranslateCodingSystem iso8859_9CodingSystem_;
+  TranslateCodingSystem koi8_rCodingSystem_;
 #ifdef WIN32
   Win32CodingSystem ansiCodingSystem_;
   Win32CodingSystem oemCodingSystem_;
@@ -246,6 +248,15 @@
   { CharsetRegistry::UNREGISTERED, 0x0 }
 };
 
+static const TranslateCodingSystem::Desc koi8_rDesc[] = {
+  { CharsetRegistry::ISO646_C0, 0x0 },
+  { CharsetRegistry::ISO646_ASCII_G0, 0x0 },
+  // FIXME: only GR part of KOI8-R is handled (i.e. 160..255)
+  //        since koi8-r does not follow ISO control/graphic model
+  { CharsetRegistry::KOI8_R, 0x80 },
+  { CharsetRegistry::UNREGISTERED, 0x0 }
+};
+
 #endif /* SP_MULTI_BYTE */
 
 const CodingSystemKitImpl::Entry CodingSystemKitImpl::bctfTable_[] = {
@@ -292,6 +303,8 @@
   { "ISO-8859-8", iso8859_8 },
   { "IS8859-9", iso8859_9 },
   { "ISO-8859-9", iso8859_9 },
+  { "KOI8-R", koi8_r }, // RFC 1489
+  { "KOI8", koi8_r },
   { "EUC-JP", eucjp },
   { "EUC-CN", euccn },
   { "GB2312", euccn },
@@ -324,6 +337,7 @@
   iso8859_7CodingSystem_(&identityCodingSystem_, iso8859_7Desc, &systemCharset_, 0x100, unicodeReplaceChar),
   iso8859_8CodingSystem_(&identityCodingSystem_, iso8859_8Desc, &systemCharset_, 0x100, unicodeReplaceChar),
   iso8859_9CodingSystem_(&identityCodingSystem_, iso8859_9Desc, &systemCharset_, 0x100, unicodeReplaceChar),
+  koi8_rCodingSystem_(&identityCodingSystem_, koi8_rDesc, &systemCharset_, 0x100, unicodeReplaceChar),
   eucjpCodingSystem_(&eucBctf_, jis2Desc, &systemCharset_, 0x8000, unicodeReplaceChar),
   euccnCodingSystem_(&eucBctf_, gbDesc, &systemCharset_, 0x8000, unicodeReplaceChar),
   euckrCodingSystem_(&eucBctf_, kscDesc, &systemCharset_, 0x8000, unicodeReplaceChar),
@@ -472,6 +486,8 @@
     return &iso8859_8CodingSystem_;
   case iso8859_9:
     return &iso8859_9CodingSystem_;
+  case koi8_r:
+    return &koi8_rCodingSystem_;
   case xml:
     return &xmlCodingSystem_;
 #ifdef WIN32
