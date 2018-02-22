--- src/ytregions.cpp.orig	2018-02-16 08:18:19 UTC
+++ src/ytregions.cpp
@@ -84,7 +84,7 @@ YTRegion YTRegions::r(const QString &nam
 }
 
 const YTRegion &YTRegions::localRegion() {
-    static const YTRegion region = [] {
+    static const YTRegion region = []() -> const YTRegion { // workaround for https://github.com/flaviotordini/minitube/issues/99
         QString country = QLocale::system().name().right(2);
         for (const YTRegion &r : list()) {
             if (r.id == country) return r;
