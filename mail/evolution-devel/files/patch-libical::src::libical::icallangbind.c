
$FreeBSD$

--- libical/src/libical/icallangbind.c	2001/11/20 12:10:52	1.1
+++ libical/src/libical/icallangbind.c	2001/11/20 12:11:22
@@ -22,7 +22,9 @@
 #include "icalproperty.h"
 #include "icalerror.h"
 #include "icalmemory.h"
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
 #include <string.h>
 
 int* icallangbind_new_array(int size){
