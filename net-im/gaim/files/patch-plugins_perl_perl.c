--- plugins/perl/perl.c.orig	Thu Jul 17 12:43:32 2003
+++ plugins/perl/perl.c	Thu Jul 17 12:46:06 2003
@@ -23,6 +23,10 @@
  * X-Chat Copyright (C) 1998 Peter Zelezny.
  *
  */
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #ifdef DEBUG
 # undef DEBUG
 #endif
