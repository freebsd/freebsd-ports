--- mozilla-plugin/src/openvrml.cpp.orig	Sun Jul  3 10:31:21 2005
+++ mozilla-plugin/src/openvrml.cpp	Fri Jul 22 18:51:12 2005
@@ -45,6 +45,11 @@
 # endif
 # include "openvrml.h"
 
+# if defined(__FreeBSD__)
+#   include <sys/types.h>
+#   include <signal.h>
+# endif
+
 namespace {
 
     void printerr(const char * str);
