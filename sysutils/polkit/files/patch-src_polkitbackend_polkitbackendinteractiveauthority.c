--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2012-05-15 21:52:38.000000000 +0200
+++ src/polkitbackend/polkitbackendinteractiveauthority.c	2012-05-15 21:52:49.000000000 +0200
@@ -279,7 +279,7 @@
   static volatile GQuark domain = 0;
 
   /* Force registering error domain */
-  domain = POLKIT_ERROR; domain;
+  domain = POLKIT_ERROR;
 
   priv = POLKIT_BACKEND_INTERACTIVE_AUTHORITY_GET_PRIVATE (authority);
 
