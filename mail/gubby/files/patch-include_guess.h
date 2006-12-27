
$FreeBSD$

--- include/guess.h.orig
+++ include/guess.h
@@ -38,7 +38,7 @@
 public:
 	guess();
 
-	inline const std::string guess::str() const {
+	inline const std::string str() const {
 		return procmaillog;
 	}
 
