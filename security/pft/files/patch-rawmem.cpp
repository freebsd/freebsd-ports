--- rawmem.cpp.orig	Sat Jul  6 18:36:21 2002
+++ rawmem.cpp	Thu Aug  5 18:53:38 2004
@@ -2,7 +2,7 @@
  *
  * $Id: rawmem.cpp,v 1.2 2002/01/07 17:18:49 fx Exp $
  */
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
@@ -10,10 +10,14 @@
 #ifndef UNIX
 #include <winsock2.h>
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
-#endif UNIX
+#endif // UNIX
 
 #include "rawmem.h"
+
+using namespace std;
 
 Rawmem::Rawmem() {
 	mem=NULL;
