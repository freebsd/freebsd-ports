--- latex-table.cc.orig	Thu Oct  8 03:12:09 1998
+++ latex-table.cc	Wed Mar 31 20:14:59 2004
@@ -18,7 +18,8 @@
 #endif /* HAVE_ALLOCA_H */
 #endif /* __GNUC__ */
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #include <stdlib.h>
 #ifdef HAVE_STRING_H
