
$FreeBSD$

--- include/initcurs.h.orig
+++ include/initcurs.h
@@ -41,7 +41,7 @@
 	initcurs();
 	~initcurs();
 
-	inline bool initcurs::hascolors() const {
+	inline bool hascolors() const {
 		return colors;
 	}
 
