--- src/libecap/common/area.h.orig	2011-02-17 21:04:23.000000000 +0300
+++ src/libecap/common/area.h	2014-09-12 15:16:00.000000000 +0400
@@ -45,7 +45,8 @@
 		Details details; // creator-defined
 
 	private:
-		bool does_not_support_comparisons() const; // not implemented
+		template<typename T> bool operator==(const T&) {}
+		template<typename T> bool operator!=(const T&) {}
 };
 
 // this stub can be enhanced by area creators to optimize area operations
@@ -57,10 +58,8 @@
 std::ostream &operator <<(std::ostream &os, const Area &area);
 
 /* make Area comparisons illegal by default */
-template <typename T> bool operator ==(const Area &a, const T &) { return a.does_not_support_comparisons(); }
-template <typename T> bool operator !=(const Area &a, const T &) { return a.does_not_support_comparisons(); }
-template <typename T> bool operator ==(const T &, const Area &a) { return a.does_not_support_comparisons(); }
-template <typename T> bool operator !=(const T &, const Area &a) { return a.does_not_support_comparisons(); }
+template <typename T> bool operator ==(const T &t, const Area &a) { return a == t; }
+template <typename T> bool operator !=(const T &t, const Area &a) { return a != t; }
 
 } // namespace libecap
 
