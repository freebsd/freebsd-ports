--- src/lirc.c.orig	2011-08-07 20:20:33.000000000 +0900
+++ src/lirc.c	2012-05-15 03:54:41.000000000 +0900
@@ -223,8 +223,8 @@
   if (gxine_lirc_thread_created)
     pthread_join (gxine_lirc_thread, NULL);
   gxine_lirc_start ();
-#endif
   JS_SET_RVAL (cx, vp, gxine_lirc_thread ? JSVAL_TRUE : JSVAL_FALSE);
+#endif
   return JS_TRUE;
 }
 
