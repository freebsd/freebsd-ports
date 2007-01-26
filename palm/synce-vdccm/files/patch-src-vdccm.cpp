--- src/vdccm.cpp.orig	Fri Jan 26 19:24:38 2007
+++ src/vdccm.cpp	Fri Jan 26 19:26:01 2007
@@ -34,7 +34,7 @@
 #include <localserversocket.h>
 #include <synce_log.h>
 #include <iostream>
-#include <wait.h>
+#include <sys/wait.h>
 
 using namespace synce;
 using namespace std;
