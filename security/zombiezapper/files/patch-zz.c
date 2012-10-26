--- zz.c.orig	Wed Mar  5 13:16:37 2003
+++ zz.c	Wed Mar  5 13:16:42 2003
@@ -104,7 +104,7 @@
   union
   {
     struct in_addr addr;
-    ulong temp_ip;
+    u_long temp_ip;
   } ip;
   
   for (i = 0; i < 256; i++)
