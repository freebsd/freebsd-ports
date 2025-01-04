--- external/permlib/include/permlib/predicate/subgroup_predicate.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/predicate/subgroup_predicate.h
@@ -42,7 +42,7 @@ template <class PERM>
 
 /// abstract base class for subgroup (and coset) predicates
 template <class PERM>
-class SubgroupPredicate : public std::unary_function<PERM, bool> {
+class SubgroupPredicate {
 public:
 	/// virtual destructor
 	virtual ~SubgroupPredicate() {}
