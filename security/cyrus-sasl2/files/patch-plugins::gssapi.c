--- plugins/gssapi.c.orig	Fri Mar  9 23:56:46 2001
+++ plugins/gssapi.c	Mon Jan 21 21:03:32 2002
@@ -71,6 +71,12 @@
 #include <saslutil.h>
 #include <saslplug.h>
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
+#include <errno.h>
+
 #ifdef WIN32
 /* This must be after sasl.h */
 # include "saslgssapi.h"
