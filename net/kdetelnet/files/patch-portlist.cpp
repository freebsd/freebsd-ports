--- ktelnet2/portlist.cpp.orig	Fri Dec 29 02:56:18 2000
+++ ktelnet2/portlist.cpp	Fri May  4 01:12:41 2001
@@ -19,6 +19,7 @@
 #include <iostream.h>
 
 #include "portlist.h"
+#include <sys/types.h>
 #include <netinet/in.h>
 
 
