--- html-table.cc.orig	Fri Aug  6 09:12:08 1999
+++ html-table.cc	Wed Mar 31 20:10:02 2004
@@ -3,7 +3,8 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #include <stdlib.h>
 #ifdef HAVE_STRING_H
@@ -17,7 +18,8 @@
 #define __EXCLUDE_READER_CLASSES
 #include "lib.h"
 #ifndef HAVE_ALLOCA_H
-extern "C" char *alloca(int);
+/* extern "C" char *alloca(int); */
+#include <stdlib.h> /* stupid linux specific weenie code. */
 #else
 #include <alloca.h>
 #endif /* HAVE_ALLOCA_H */
