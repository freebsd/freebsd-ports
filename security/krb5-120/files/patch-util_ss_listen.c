--- util/ss/listen.c.orig	2023-08-07 11:38:21.000000000 -0700
+++ util/ss/listen.c	2023-08-09 13:09:30.816661000 -0700
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
