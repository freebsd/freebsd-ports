--- kdiff3/pdiff.cpp.orig      Mon Apr  7 21:12:32 2003
+++ kdiff3/pdiff.cpp   Mon Apr  7 21:13:01 2003
@@ -53,6 +53,7 @@
 #else
 #include <unistd.h>
 #endif
+#include <errno.h>

 using namespace std;

