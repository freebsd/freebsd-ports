--- lib/arglex.cc.orig	Sat May 20 23:56:52 2006
+++ lib/arglex.cc	Thu May 25 12:36:38 2006
@@ -21,6 +21,11 @@
 
 #include <cctype>
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#include <stdio.h>
+#endif
+
 #include <arglex.h>
 #include <progname.h>
 #include <quit.h>
