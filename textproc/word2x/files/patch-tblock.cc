--- tblock.cc.orig	Thu Oct  8 03:12:09 1998
+++ tblock.cc	Wed Mar 31 20:11:29 2004
@@ -11,7 +11,8 @@
 #ifdef HAVE_STRINGS_H
 #include <strings.h>
 #endif /* HAVE_STRINGS_H */
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include "tblock.h"
 
 const struct tblock::block tblock::dummy_init={0,0,NULL,NULL};
