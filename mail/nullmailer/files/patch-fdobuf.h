--- lib/fdbuf/fdobuf.h~	Sat Mar  5 01:12:32 2005
+++ lib/fdbuf/fdobuf.h	Sat Mar  5 01:12:53 2005
@@ -17,6 +17,8 @@
 #ifndef FDBUF__FDOBUF__H__
 #define FDBUF__FDOBUF__H__
 
+#include <pwd.h>
+
 class fdobuf : protected fdbuf
 {
 public:
