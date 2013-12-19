--- lib/diff.hh.orig	2013-12-07 05:09:56.000000000 +0900
+++ lib/diff.hh	2013-12-07 05:10:09.000000000 +0900
@@ -13,7 +13,7 @@
 template<>
 struct less<xmlNodePtr>
 {
-    bool operator()(xmlNodePtr m, xmlNodePtr n)
+    bool operator()(xmlNodePtr m, xmlNodePtr n) const
     {
 	return compare(m, n, true) < 0;
     }
