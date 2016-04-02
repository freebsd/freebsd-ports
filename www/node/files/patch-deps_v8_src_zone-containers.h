--- deps/v8/src/zone-containers.h.orig	2016-03-16 21:22:58.000000000 +0100
+++ deps/v8/src/zone-containers.h	2016-03-24 23:34:37.741885000 +0100
@@ -114,12 +114,12 @@ class ZoneSet : public std::set<K, Compa
 // a zone allocator.
 template <typename K, typename V, typename Compare = std::less<K>>
 class ZoneMap
-    : public std::map<K, V, Compare, zone_allocator<std::pair<K, V>>> {
+    : public std::map<K, V, Compare, zone_allocator<std::pair<const K, V>>> {
  public:
   // Constructs an empty map.
   explicit ZoneMap(Zone* zone)
-      : std::map<K, V, Compare, zone_allocator<std::pair<K, V>>>(
-            Compare(), zone_allocator<std::pair<K, V>>(zone)) {}
+      : std::map<K, V, Compare, zone_allocator<std::pair<const K, V>>>(
+            Compare(), zone_allocator<std::pair<const K, V>>(zone)) {}
 };
 
 
