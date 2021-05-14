--- src/uncrustify.cpp.orig	2021-05-13 14:53:40 UTC
+++ src/uncrustify.cpp
@@ -43,6 +43,7 @@
 #include "universalindentgui.h"
 #include "width.h"
 
+#include <cerrno>
 #include <fcntl.h>
 #include <map>
 #ifdef HAVE_UNISTD_H
