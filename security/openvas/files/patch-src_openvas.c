--- src/openvas.c	2022-07-31 21:26:36.888737000 -0500
+++ src/openvas.c	2022-07-31 21:28:05.607778000 -0500
@@ -44,7 +44,7 @@
 #include "sighand.h"               /* for openvas_signal */
 #include "utils.h"                 /* for store_file */
 
-#include <bsd/unistd.h> /* for proctitle_init */
+#include <unistd.h> /* for proctitle_init */
 #include <errno.h>      /* for errno() */
 #include <fcntl.h>      /* for open() */
 #include <gcrypt.h>     /* for gcry_control */
@@ -468,11 +468,19 @@
  * @param argv Argument vector.
  */
 int
+#if defined(__FreeBSD__)
+openvas (int argc, char *argv[])
+ 
+{
+  int err;
+#else
 openvas (int argc, char *argv[], char *env[])
+
 {
   int err;
 
   setproctitle_init (argc, argv, env);
+#endif
   gcrypt_init ();
 
   static gboolean display_version = FALSE;
