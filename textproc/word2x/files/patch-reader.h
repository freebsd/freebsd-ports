--- reader.h.orig	Thu Oct  8 03:12:09 1998
+++ reader.h	Wed Mar 31 20:12:28 2004
@@ -13,7 +13,8 @@
 #ifdef HAVE_STRINGS_H
 #include <strings.h>
 #endif /* HAVE_STRINGS_H */
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include "tblock.h"
 #include "interface.h"
 #include "fifo.h"
