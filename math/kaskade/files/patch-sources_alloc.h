--- ./sources/alloc.h.orig	Fri Dec 10 15:19:05 1999
+++ ./sources/alloc.h	Tue Aug 16 22:42:54 2005
@@ -3,7 +3,8 @@
 #ifndef ALLOC_H
 #define ALLOC_H
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "stack.h"
 
