--- src/setup_config.h.orig	Wed Oct  9 11:44:19 2002
+++ src/setup_config.h	Tue Dec 31 16:17:38 2002
@@ -11,6 +11,7 @@
 
 #ifdef HAVE_REGEX_H
 extern "C" {
+#  include <sys/types.h>
 #  include <regex.h>
 }
 #endif
