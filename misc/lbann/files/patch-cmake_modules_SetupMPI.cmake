-- Ensure the MPI C component is discovered, not just CXX. The dependency
-- math/hydrogen already calls find_package(MPI COMPONENTS CXX) in its
-- CMake config, which leaves MPI_C_FOUND unset. Because science/conduit
-- exports targets (conduit_relay_mpi, conduit_relay_mpi_io,
-- conduit_blueprint_mpi) that link against MPI::MPI_C, LBANN must also
-- request the C component or CMake fails with:
--   "The link interface of target ... contains: MPI::MPI_C but the target
--    was not found."

--- cmake/modules/SetupMPI.cmake.orig	2023-11-08 01:08:28 UTC
+++ cmake/modules/SetupMPI.cmake
@@ -26,8 +26,10 @@
 
 # This module configures MPI and ensures the library is setup properly
 
-if (NOT MPI_CXX_FOUND)
-  find_package(MPI REQUIRED COMPONENTS CXX)
+if (NOT MPI_CXX_FOUND OR NOT MPI_C_FOUND)
+  # Request C as well as CXX: science/conduit exports MPI targets that
+  # link against MPI::MPI_C, so the C component must be available.
+  find_package(MPI REQUIRED COMPONENTS C CXX)
 endif ()
 
 if (NOT TARGET MPI::MPI_CXX)
