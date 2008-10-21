--- mod_ntlm.c.orig	2003-02-23 17:58:02.000000000 +0200
+++ mod_ntlm.c	2008-10-06 16:34:55.000000000 +0300
@@ -587,7 +587,7 @@
         return NULL;
     }
 
-    apr_pool_sub_make(&sp,p,NULL);
+    apr_pool_create_ex(&sp,p,NULL,NULL);
 
     while (!(ap_cfg_getline(l, MAX_STRING_LEN, f))) {
         if ((l[0] == '#') || (!l[0]))
