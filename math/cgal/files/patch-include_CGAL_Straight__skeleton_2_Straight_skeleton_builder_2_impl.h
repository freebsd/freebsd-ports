--- include/CGAL/Straight_skeleton_2/Straight_skeleton_builder_2_impl.h.orig	2014-08-29 14:14:56 UTC
+++ include/CGAL/Straight_skeleton_2/Straight_skeleton_builder_2_impl.h
@@ -21,6 +21,13 @@
 
 #include <boost/bind.hpp>
 #include <boost/utility.hpp>
+
+// Workaround for boost bug #11880
+#include <boost/version.hpp>
+#if BOOST_VERSION == 106000
+	#include <boost/type_traits/ice.hpp>
+#endif
+
 #include <boost/graph/adjacency_matrix.hpp>
 #include <CGAL/Unique_hash_map.h>
 
