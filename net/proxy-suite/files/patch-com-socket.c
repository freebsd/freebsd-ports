--- common/com-socket.c	Tue Mar 30 12:31:32 2004
+++ common/com-socket.c	Mon Dec 20 17:33:39 2004
@@ -84,6 +84,9 @@
 #if defined(HAVE_STROPTS_H)
 #   include <stropts.h>
 #endif
+#if defined(HAVE_SYS_PARAM_H)
+#   include <sys/param.h>
+#endif
 #if defined(HAVE_SYS_CONF_H)
 #   include <sys/conf.h>
 #endif
