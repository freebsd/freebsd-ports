--- src/lirc.c.orig	2017-12-27 17:41:32 UTC
+++ src/lirc.c
@@ -226,8 +226,8 @@ static JSBool js_reload_lirc (JSContext *cx, uintN arg
   if (gxine_lirc_thread_created)
     pthread_join (gxine_lirc_thread, NULL);
   gxine_lirc_start ();
-#endif
   JS_SET_RVAL (cx, vp, gxine_lirc_thread_created ? JSVAL_TRUE : JSVAL_FALSE);
+#endif
   return JS_TRUE;
 }
 
