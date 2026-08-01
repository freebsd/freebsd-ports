-- KFAC relies on the Aluminum (::Al) library. Only register the KFAC
-- builder when LBANN is built with Aluminum support.

--- src/execution_algorithms/factory.cpp.orig	2026-08-01 17:36:16 UTC
+++ src/execution_algorithms/factory.cpp
@@ -24,7 +24,9 @@
 // permissions and limitations under the license.
 ////////////////////////////////////////////////////////////////////////////////
 #include "lbann/execution_algorithms/factory.hpp"
+#ifdef LBANN_HAS_ALUMINUM
 #include "lbann/execution_algorithms/kfac.hpp"
+#endif
 #include "lbann/execution_algorithms/ltfb.hpp"
 #include "lbann/execution_algorithms/sgd_training_algorithm.hpp"
 #include "lbann/utils/make_abstract.hpp"
@@ -41,7 +43,9 @@ lbann::TrainingAlgorithmFactory build_default_factory(
   lbann::TrainingAlgorithmFactory fact;
   fact.register_builder("SGD", lbann::make<lbann::SGDTrainingAlgorithm>);
   fact.register_builder("LTFB", lbann::make<lbann::LTFB>);
+#ifdef LBANN_HAS_ALUMINUM
   fact.register_builder("KFAC", lbann::make<lbann::KFAC>);
+#endif
   return fact;
 }
 
