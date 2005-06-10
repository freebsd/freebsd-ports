--- knzb/downloadmanager.cpp.orig	Fri Jun 10 13:41:59 2005
+++ knzb/downloadmanager.cpp	Fri Jun 10 13:43:24 2005
@@ -15,6 +15,8 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <unistd.h>
+
 #include <qfile.h>
 #include <qstringlist.h>
 #include <qptrlist.h>
