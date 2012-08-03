--- tclUnixPort.h.orig	2012-08-02 15:43:23.269506562 +0200
+++ tclUnixPort.h	2012-08-02 15:43:25.167507612 +0200
@@ -631,7 +631,9 @@
 EXTERN struct tm *TclpGmtime(CONST time_t *);
 /* #define localtime(x)	TclpLocaltime(x)
  * #define gmtime(x)	TclpGmtime(x)    */
-#   undef inet_ntoa
+#   ifdef inet_ntoa
+#       undef inet_ntoa
+#   endif
 #   define inet_ntoa(x)	TclpInetNtoa(x)
 #   ifdef HAVE_PTHREAD_ATTR_GET_NP
 #	define TclpPthreadGetAttrs	pthread_attr_get_np
