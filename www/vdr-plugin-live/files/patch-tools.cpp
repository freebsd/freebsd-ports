--- a/tools.cpp
+++ a/tools.cpp
@@ -12,6 +12,9 @@
 #include "tools.h"
 #include "md5.h"
 
+#ifdef __FreeBSD__
+#define O_LARGEFILE 0
+#endif
 
 using namespace std;
 using namespace tnt;
