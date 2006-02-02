--- debug.c.orig	Sun Jul 10 10:12:33 2005
+++ debug.c	Thu Feb  2 09:40:00 2006
@@ -66,7 +66,8 @@ void ea_debug_init (TSRMLS_D)
 void ea_debug_shutdown ()
 {
     fflush (F_fp);
-    fclose (F_fp);
+    if (F_fp != stderr)
+        fclose (F_fp);
     F_fp = NULL;
 }
 
