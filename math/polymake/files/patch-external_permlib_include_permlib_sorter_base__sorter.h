--- external/permlib/include/permlib/sorter/base_sorter.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/sorter/base_sorter.h
@@ -39,7 +39,7 @@ template<class ORDER>
 
 /// A sorter that sorts a sequence with respect to a given input ordering
 template<class ORDER>
-class OrderedSorter : public std::binary_function<unsigned long, unsigned long, bool> {
+class OrderedSorter {
 public:
 	/// true iff a preceeds b in given sequence
 	bool operator() (unsigned long a, unsigned long b) const {
