--- external/permlib/include/permlib/bsgs.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/bsgs.h
@@ -461,7 +461,7 @@ template <class PERM>
  * stabilizer chain are next to each other.
  */
 template <class PERM>
-class StrongGeneratingSetSorter : public std::binary_function<typename PERM::ptr, typename PERM::ptr, bool> {
+class StrongGeneratingSetSorter {
 public:
 	/**
 	 * @param baseBegin begin-iterator(dom_int) to the base relative to which the strong generating set is to be sorted
