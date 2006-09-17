--- lib/krb5/os/dnsglue.c.orig	Sat Sep 16 22:57:46 2006
+++ lib/krb5/os/dnsglue.c	Sat Sep 16 22:58:25 2006
@@ -100,6 +100,7 @@
 #endif
 
 #if USE_RES_NINIT
+    memset(&statbuf, 0, sizeof statbuf);
     ret = res_ninit(&statbuf);
 #else
     ret = res_init();
