--- kcdlabel/kdirtree.cpp.orig	Mon Dec 29 02:18:03 2003
+++ kcdlabel/kdirtree.cpp	Mon Dec 29 02:18:49 2003
@@ -20,7 +20,9 @@
 #include <string>
 #include <vector>
 #include <algorithm>
+#ifndef __FreeBSD__
 #include <error.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
