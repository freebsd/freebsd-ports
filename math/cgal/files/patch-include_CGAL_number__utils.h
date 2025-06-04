--- include/CGAL/number_utils.h.orig	2024-10-19 19:02:30 UTC
+++ include/CGAL/number_utils.h
@@ -21,6 +21,7 @@
 #include <CGAL/Algebraic_structure_traits.h>
 #include <CGAL/Real_embeddable_traits.h>
 #include <CGAL/Kernel/Same_uncertainty.h>
+#include <boost/mpl/if.hpp>
 
 namespace CGAL {
 CGAL_NTS_BEGIN_NAMESPACE
