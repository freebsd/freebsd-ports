--- deps/v8/src/zone-containers.h.orig	2016-04-21 17:45:25 UTC
+++ deps/v8/src/zone-containers.h
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
 
 
