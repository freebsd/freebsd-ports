--- avahi-core/fdutil.c.orig	Sat Jun 23 02:09:02 2007
+++ avahi-core/fdutil.c	Sat Jun 23 02:09:37 2007
@@ -23,6 +23,7 @@
 #include <config.h>
 #endif
 
+#include <sys/select.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <assert.h>
