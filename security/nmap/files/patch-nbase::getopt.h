--- nbase/getopt.h.orig	Sat Mar 29 22:29:42 2003
+++ nbase/getopt.h	Sat Mar 29 22:47:18 2003
@@ -100,7 +100,11 @@
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
+#if FREEBSD
+#include <unistd.h>
+#else
 extern int getopt ();
+#endif
 #endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);
