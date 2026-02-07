--- src/vm.h.orig	2022-09-03 19:42:45 UTC
+++ src/vm.h
@@ -25,6 +25,7 @@
 #include <vector>
 #include <map>
 #include <stack>
+#include <ctime>
 
 #ifdef HAVE_LIBREADLINE
 #  if defined(HAVE_READLINE_READLINE_H)
