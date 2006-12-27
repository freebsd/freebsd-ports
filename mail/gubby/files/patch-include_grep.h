
$FreeBSD$

--- include/grep.h.orig
+++ include/grep.h
@@ -45,7 +45,7 @@
 		trig.push_back(trigger);
 	}
 
-	inline const std::string& grep::gettrigger(const int n) const {
+	inline const std::string& gettrigger(const int n) const {
 		return trig[n];
 	}
 
