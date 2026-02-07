--- util/ss/listen.c.orig	2025-08-05 14:15:15 UTC
+++ util/ss/listen.c
@@ -15,7 +15,11 @@
 #include <sys/param.h>
 
 #if defined(HAVE_LIBEDIT)
+#if defined(FreeBSD_BASE_EDITLINE)
+#include <edit/readline/readline.h>
+#else
 #include <editline/readline.h>
+#endif
 #elif defined(HAVE_READLINE)
 #include <readline/readline.h>
 #include <readline/history.h>
