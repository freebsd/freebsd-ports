--- tclUnixPort.h.orig	2015-02-12 15:13:16 UTC
+++ tclUnixPort.h
@@ -625,7 +625,9 @@ typedef int socklen_t;
 #  include <pthread.h>
 /* #define localtime(x)	TclpLocaltime(x)
  * #define gmtime(x)	TclpGmtime(x)    */
-#   undef inet_ntoa
+#   ifdef inet_ntoa
+#       undef inet_ntoa
+#   endif
 #   define inet_ntoa(x)	TclpInetNtoa(x)
 #   ifdef HAVE_PTHREAD_ATTR_GET_NP
 #	define TclpPthreadGetAttrs	pthread_attr_get_np
