--- ./src/impgp.cc.orig	2009-07-01 23:25:08.000000000 -0400
+++ ./src/impgp.cc	2009-07-01 23:25:37.000000000 -0400
@@ -13,6 +13,7 @@
 string impgp::passphrase[];
 
 impgp::impgp() {
+    gpgme_check_version(NULL);
     if(gpgme_new(&ctx))
 	ctx = 0;
 }
