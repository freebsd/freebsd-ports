--- src/security/ServerOptions.h.orig	2018-06-11 16:30:57 UTC
+++ src/security/ServerOptions.h
@@ -29,7 +29,7 @@ class ServerOptions : public PeerOptions (public)
         // is more secure to have only a small set of trusted CA.
         flags.tlsDefaultCa.defaultTo(false);
     }
-    ServerOptions(const ServerOptions &) = default;
+    ServerOptions(const ServerOptions &) = delete;
     ServerOptions &operator =(const ServerOptions &);
     ServerOptions(ServerOptions &&o) { this->operator =(o); }
     ServerOptions &operator =(ServerOptions &&o) { this->operator =(o); return *this; }
