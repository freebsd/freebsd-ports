--- include/initcurs.h.orig	2004-12-17 23:29:19.000000000 -0500
+++ include/initcurs.h	2014-07-29 18:53:52.000000000 -0400
@@ -33,6 +33,7 @@
 #undef clear
 
 #include <string>
+#include <stdlib.h>
 
 //! Curses resource-aquisition-is-initialization
 class initcurs {
@@ -41,7 +42,7 @@
 	initcurs();
 	~initcurs();
 
-	inline bool initcurs::hascolors() const {
+	inline bool hascolors() const {
 		return colors;
 	}
 
