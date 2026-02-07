--- external/permlib/include/permlib/sorter/trivial_sorter.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/sorter/trivial_sorter.h
@@ -36,7 +36,7 @@ namespace permlib {
 namespace permlib {
 
 /// A sorter that sorts a sequence in natural numerical order (1 < 2 < 3 < ...)
-class TrivialSorter : public std::binary_function<unsigned long, unsigned long, bool>{
+class TrivialSorter {
 public:
 	/// true iff a < b
 	bool operator() (unsigned long a, unsigned long b) const {
