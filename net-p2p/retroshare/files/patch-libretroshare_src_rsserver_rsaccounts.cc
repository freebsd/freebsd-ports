--- libretroshare/src/rsserver/rsaccounts.cc.orig	2018-03-13 19:25:38 UTC
+++ libretroshare/src/rsserver/rsaccounts.cc
@@ -35,6 +35,7 @@
 #endif // WINDOWS_SYS
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/stat.h>
 
 #include <iostream>
