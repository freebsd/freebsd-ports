--- lib/fdbuf/fdobuf.h.orig	Mon Nov 18 22:27:27 2002
+++ lib/fdbuf/fdobuf.h	Mon Nov 18 22:27:50 2002
@@ -17,6 +17,8 @@
 #ifndef FDBUF__FDOBUF__H__
 #define FDBUF__FDOBUF__H__
 
+#include <pwd.h>
+
 class fdobuf : protected fdbuf
 {
 public:
