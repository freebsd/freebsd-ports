
$FreeBSD$

--- libversit/vcc.y	2001/11/20 12:31:59	1.1
+++ libversit/vcc.y	2001/11/20 12:32:39
@@ -107,7 +107,7 @@
 #endif
 
 #include <string.h>
-#ifndef __MWERKS__
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
 #endif
 #include <stdio.h>
