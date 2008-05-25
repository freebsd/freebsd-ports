--- encfs/encfsctl.cpp.orig	2008-05-22 02:37:48.000000000 -0700
+++ encfs/encfsctl.cpp	2008-05-22 02:37:57.000000000 -0700
@@ -36,9 +36,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #ifdef __FreeBSD__
-#include <libintl.h>
+#include "gettext.h"
 #endif
 
 #include "i18n.h"
 
