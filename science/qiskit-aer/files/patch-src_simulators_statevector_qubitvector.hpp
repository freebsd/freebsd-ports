- https://github.com/Qiskit/qiskit-aer/issues/2284

--- src/simulators/statevector/qubitvector.hpp.orig	2025-01-16 05:21:07 UTC
+++ src/simulators/statevector/qubitvector.hpp
@@ -729,16 +729,6 @@ template <typename data_t>
 }
 
 template <typename data_t>
-void QubitVector<data_t>::check_dimension(const QubitVector &qv) const {
-  if (data_size_ != qv.size_) {
-    std::string error = "QubitVector: vectors are different shape " +
-                        std::to_string(data_size_) +
-                        " != " + std::to_string(qv.num_states_);
-    throw std::runtime_error(error);
-  }
-}
-
-template <typename data_t>
 void QubitVector<data_t>::check_checkpoint() const {
   if (!checkpoint_) {
     throw std::runtime_error(
