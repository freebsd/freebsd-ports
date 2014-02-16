--- src/lib/libpsio/psio.hpp.orig
+++ src/lib/libpsio/psio.hpp
@@ -157,10 +157,11 @@
 
   };
   
-extern "C" {
-  extern int psiopp_ipv1_config(PSIO *psio_obj);
-}
   extern PSIO* _default_psio_lib_;
 }
 
+extern "C" {
+  int psiopp_ipv1_config(psi::PSIO *psio_obj);
+}
+
 #endif /* header guard */
