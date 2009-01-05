--- CimXml.h.orig	2008-12-22 00:31:07.000000000 +0900
+++ CimXml.h	2008-12-22 00:31:36.000000000 +0900
@@ -33,7 +33,7 @@
 #include <vector>
 #include <iostream>
 
-#if defined __GNUC__
+#if defined __GNUC__ && !defined(__FreeBSD__)
 #include <ansidecl.h>
 #endif
 
