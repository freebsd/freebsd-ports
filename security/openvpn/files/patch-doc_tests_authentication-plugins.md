--- doc/tests/authentication-plugins.md.orig	2025-04-02 06:53:10 UTC
+++ doc/tests/authentication-plugins.md
@@ -36,7 +36,7 @@ To build the needed authentication plug-in, run:
       verb 4
       dev tun
       server 10.8.0.0 255.255.255.0
-      dh sample/sample-keys/dh2048.pem
+      dh none
       ca sample/sample-keys/ca.crt
       cert sample/sample-keys/server.crt
       key sample/sample-keys/server.key
