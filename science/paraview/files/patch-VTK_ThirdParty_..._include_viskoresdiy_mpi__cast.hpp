--- VTK/ThirdParty/viskores/vtkviskores/viskores/viskores/thirdparty/diy/viskoresdiy/include/viskoresdiy/mpi/mpi_cast.hpp.orig	2025-09-25 09:24:50 UTC
+++ VTK/ThirdParty/viskores/vtkviskores/viskores/viskores/thirdparty/diy/viskoresdiy/include/viskoresdiy/mpi/mpi_cast.hpp
@@ -5,7 +5,7 @@
 /// to thier correct types.
 
 #ifndef VISKORESDIY_HAS_MPI
-#  include <mpi.h>
+#  include <vtk_mpi.h>
 #endif
 
 namespace diy
