--- ./libs/libmythtv/util-opengl.cpp.orig	2007-12-11 23:51:42.000000000 -0500
+++ ./libs/libmythtv/util-opengl.cpp	2009-04-22 21:05:20.000000000 -0400
@@ -306,7 +306,9 @@
 {
     __GLXextFuncPtr ret = NULL;
 
-#if GLX_VERSION_1_4
+#if USING_GLX_PROC_ADDR_ARB
+    X11S(ret = glXGetProcAddressARB((const GLubyte*)procName.latin1()));
+#elif GLX_VERSION_1_4
     X11S(ret = glXGetProcAddress((const GLubyte*)procName.latin1()));
 #elif GLX_ARB_get_proc_address
     X11S(ret = glXGetProcAddressARB((const GLubyte*)procName.latin1()));
