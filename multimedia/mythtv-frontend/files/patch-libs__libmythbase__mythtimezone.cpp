--- libs/libmythbase/mythtimezone.cpp.orig	2013-09-18 20:06:08.000000000 +0000
+++ libs/libmythbase/mythtimezone.cpp	2013-10-18 16:01:39.000000000 +0000
@@ -1,6 +1,7 @@
 #include "mythtimezone.h"
 
 #include <stdlib.h> // for malloc, getenv
+#include <time.h>
 
 #include <QDataStream>
 #include <QTextStream>
