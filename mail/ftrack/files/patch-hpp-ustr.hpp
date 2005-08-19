--- hpp/ustr.hpp.orig	Fri Aug 19 17:22:08 2005
+++ hpp/ustr.hpp	Fri Aug 19 17:22:52 2005
@@ -24,7 +24,9 @@
 
 #include <stddef.h>
 #include <ctype.h>
-#include <iostream.h>
+#include <iostream>
+
+using namespace std;
 
 class Str {
 private:
@@ -81,4 +83,4 @@
 
 
 
-#endif
\ No newline at end of file
+#endif
