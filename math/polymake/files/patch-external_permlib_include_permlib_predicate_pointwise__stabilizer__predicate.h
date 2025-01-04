--- external/permlib/include/permlib/predicate/pointwise_stabilizer_predicate.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/predicate/pointwise_stabilizer_predicate.h
@@ -39,7 +39,7 @@ template <class PERM>
 
 /// predicate matching a permutation if it stabilizes a given list of points pointwise
 template <class PERM>
-class PointwiseStabilizerPredicate : public std::unary_function<typename PERM::ptr, bool> {
+class PointwiseStabilizerPredicate {
 public:
 	/// constructor
 	/**
