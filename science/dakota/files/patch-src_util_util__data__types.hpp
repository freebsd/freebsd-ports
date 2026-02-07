- https://github.com/snl-dakota/dakota/issues/180

--- src/util/util_data_types.hpp.orig	2025-03-30 07:57:31 UTC
+++ src/util/util_data_types.hpp
@@ -21,6 +21,7 @@
 #include <boost/serialization/array.hpp>
 #include <boost/serialization/serialization.hpp>
 #define EIGEN_MATRIX_PLUGIN "util_eigen_plugins.hpp"
+#undef Success // https://github.com/snl-dakota/dakota/issues/180
 #include "Eigen/Dense"
 
 /// dakota (lowercase) namespace for new %Dakota modules
