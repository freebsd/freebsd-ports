--- y4mdenoise/Region2D.hh.orig	2021-09-05 06:14:13 UTC
+++ y4mdenoise/Region2D.hh
@@ -404,6 +404,7 @@ Region2D<INDEX,SIZE>::~Region2D()
 
 
 
+#if 0
 // Add the given horizontal extent to the region.
 template <class INDEX, class SIZE>
 template <class REGION, class REGION_TEMP>
@@ -480,6 +481,7 @@ error:
 	PrintRegion (a_rTemp);
 	assert (false);
 }
+#endif
 
 
 
@@ -513,6 +515,7 @@ Region2D<INDEX,SIZE>::Union (Status_t &a_reStatus,
 
 
 
+#if 0
 // Make the current region represent the union between itself
 // and the other given region.
 template <class INDEX, class SIZE>
@@ -686,6 +689,7 @@ error:
 	PrintRegion (a_rTemp);
 	assert (false);
 }
+#endif
 
 
 
