--- src/security/ServerOptions.h.orig	2019-02-19 02:46:22 UTC
+++ src/security/ServerOptions.h
@@ -35,7 +35,7 @@ class ServerOptions : public PeerOptions (public)
         // is more secure to have only a small set of trusted CA.
         flags.tlsDefaultCa.defaultTo(false);
     }
-    ServerOptions(const ServerOptions &) = default;
+    ServerOptions(const ServerOptions &) = delete;
     ServerOptions &operator =(const ServerOptions &);
     ServerOptions(ServerOptions &&o) { this->operator =(o); }
     ServerOptions &operator =(ServerOptions &&o) { this->operator =(o); return *this; }
