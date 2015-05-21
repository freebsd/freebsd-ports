--- lib/utils/map.c.orig	2015-05-02 14:52:48 UTC
+++ lib/utils/map.c
@@ -22,7 +22,7 @@
 #include "map.h"
 
 static int
-qtcStrMapItemCompare(const void *_left, const void *_right, void *_map)
+qtcStrMapItemCompare(void *_map, const void *_left, const void *_right)
 {
     const char **left = (const char**)_left;
     const char **right = (const char**)_right;
@@ -36,7 +36,7 @@ qtcStrMapInit(QtcStrMap *map)
 {
     QTC_RET_IF_FAIL(map && !map->inited && map->items && map->size && map->num);
     qsort_r(map->items, map->num, map->size,
-            qtcStrMapItemCompare, map);
+            map, qtcStrMapItemCompare);
     map->inited = true;
 }
 
