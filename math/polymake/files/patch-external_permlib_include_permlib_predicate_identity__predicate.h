--- external/permlib/include/permlib/predicate/identity_predicate.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/predicate/identity_predicate.h
@@ -39,7 +39,7 @@ template <class PERM>
 
 /// predicate matching a permutation if it stabilizes a given list of points pointwise
 template <class PERM>
-class IdentityPredicate : public std::unary_function<typename PERM::ptr, bool> {
+class IdentityPredicate {
 public:
 	/// evaluate predicate
 	bool operator()(const typename PERM::ptr &p) const {
