--- VTK/ThirdParty/vtkm/vtkvtkm/vtk-m/vtkm/thirdparty/diy/vtkmdiy/include/vtkmdiy/mpi/mpi_cast.hpp.orig	2024-12-29 23:38:49 UTC
+++ VTK/ThirdParty/vtkm/vtkvtkm/vtk-m/vtkm/thirdparty/diy/vtkmdiy/include/vtkmdiy/mpi/mpi_cast.hpp
@@ -5,7 +5,7 @@
 /// to thier correct types.
 
 #ifndef VTKMDIY_HAS_MPI
-#  include <mpi.h>
+#  include <vtk_mpi.h>
 #endif
 
 namespace diy
