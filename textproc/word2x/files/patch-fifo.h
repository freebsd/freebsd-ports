--- fifo.h.orig	Fri Aug  6 09:09:02 1999
+++ fifo.h	Wed Mar 31 20:12:59 2004
@@ -4,7 +4,8 @@
 #ifndef __FIFO_H__
 #define __FIFO_H__
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stddef.h>
 #ifndef NULL
 #define NULL (void *) 0
