
$FreeBSD$

--- libversit/vobject.c	2001/11/20 12:33:21	1.1
+++ libversit/vobject.c	2001/11/20 12:33:50
@@ -42,7 +42,7 @@
  * vobject, and convert a vobject into its textual representation.
  */
 
-#ifndef	 MWERKS
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
 #endif
 
