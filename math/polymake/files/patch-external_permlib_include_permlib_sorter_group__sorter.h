--- external/permlib/include/permlib/sorter/group_sorter.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/sorter/group_sorter.h
@@ -39,7 +39,7 @@ template <class PERM>
 
 /// A sorter that sorts a sequence of permutations with respect to a ordering induced by a base
 template <class PERM>
-class GroupSorter : public std::binary_function<PERM, PERM, bool>{
+class GroupSorter {
 public:
 	/// constructor
 	/**
