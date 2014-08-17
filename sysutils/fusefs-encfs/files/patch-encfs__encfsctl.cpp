--- encfs/encfsctl.cpp.orig	2014-08-17 19:49:24 UTC
+++ encfs/encfsctl.cpp
@@ -40,7 +40,8 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #ifdef __FreeBSD__
-#include <libintl.h>
+#include "gettext.h"
+#include <climits>
 #endif
 
 #include "i18n.h"
