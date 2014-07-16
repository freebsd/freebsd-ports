Build fix, at least building with libc++ fails because LC_ALL is not defined if
locale.h is not included.

Submitted upstream: http://article.gmane.org/gmane.editors.lyx.devel/152732
--- src/support/os_unix.cpp
+++ src/support/os_unix.cpp
@@ -23,6 +23,7 @@
 #include "support/lassert.h"
 
 #include <limits.h>
+#include <locale.h>
 #include <stdlib.h>
 
 #ifdef __APPLE__

