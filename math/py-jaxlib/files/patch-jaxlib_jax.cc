-- MPI collectives (mpitrampoline) are Linux-only; skip them on FreeBSD. Not supported upstream.
--- jaxlib/jax.cc.orig	2026-10-20 13:31:57 UTC
+++ jaxlib/jax.cc
@@ -93,7 +93,7 @@ limitations under the License.
 #include "xla/backends/cpu/collectives/gloo_kv_store.h"  // NOLINT
 #endif  // defined(__linux__)
 
-#if !defined(_WIN32) && !defined(PLATFORM_GOOGLE)
+#if !defined(_WIN32) && !defined(__FreeBSD__) && !defined(PLATFORM_GOOGLE)
 #include "xla/backends/cpu/collectives/mpi_collectives.h"
 #endif  // !_WIN32 && !PLATFORM_GOOGLE
 
@@ -434,7 +434,7 @@ NB_MODULE(_jax, m) {
       nb::arg("distributed_client"), nb::arg("hostname").none() = std::nullopt,
       nb::arg("interface").none() = std::nullopt);
 
-#if !defined(_WIN32) && !defined(PLATFORM_GOOGLE)
+#if !defined(_WIN32) && !defined(__FreeBSD__) && !defined(PLATFORM_GOOGLE)
   nb::class_<xla::cpu::MpiCollectives> mpi_collectives(m, "MpiCollectives",
                                                        cpu_collectives);
   mpi_collectives.def("Init", &xla::cpu::MpiCollectives::Init);
