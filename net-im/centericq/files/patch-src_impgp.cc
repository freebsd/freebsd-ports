--- ./src/impgp.cc.orig	2009-07-01 23:19:00.000000000 -0400
+++ ./src/impgp.cc	2009-07-01 23:19:29.000000000 -0400
@@ -12,6 +12,7 @@
 string impgp::passphrase[];
 
 impgp::impgp() {
+    gpgme_check_version(NULL);
     if(gpgme_new(&ctx))
 	ctx = 0;
 }
