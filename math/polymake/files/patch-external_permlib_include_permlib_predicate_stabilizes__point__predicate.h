--- external/permlib/include/permlib/predicate/stabilizes_point_predicate.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/predicate/stabilizes_point_predicate.h
@@ -39,7 +39,7 @@ template <class PERM>
 
 /// predicate matching points that are stabilized by given permutations
 template <class PERM>
-class StabilizesPointPredicate : public std::unary_function<unsigned long, bool> {
+class StabilizesPointPredicate {
 public:
 	/// constructor
 	/**
