--- contrib/xwintoppm/dsimple.c.orig	1998-02-13 07:48:29 UTC
+++ contrib/xwintoppm/dsimple.c
@@ -55,6 +55,10 @@ void out();
 void blip();
 Window Window_With_Name();
 void Fatal_Error();
+void usage(void);
+
+/* forward */
+void outl();
 
 /*
  * Just_display: A group of routines designed to make the writting of simple
@@ -495,6 +499,7 @@ Window Window_With_Name(dpy, top, name)
  *       printf with up to 7 arguments.
  */
 /* VARARGS1 */
+void
 outl(msg, arg0,arg1,arg2,arg3,arg4,arg5,arg6)
      char *msg;
      char *arg0, *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
