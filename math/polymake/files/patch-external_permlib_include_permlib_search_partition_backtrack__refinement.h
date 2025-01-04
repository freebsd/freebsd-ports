--- external/permlib/include/permlib/search/partition/backtrack_refinement.h.orig	2024-09-24 09:32:47 UTC
+++ external/permlib/include/permlib/search/partition/backtrack_refinement.h
@@ -67,7 +67,7 @@ class BacktrackRefinement : public Refinement<PERM> { 
 	
 	typedef typename Refinement<PERM>::RefinementPtr RefinementPtr;
 	
-	struct RefinementSorter : public std::binary_function<RefinementPtr, RefinementPtr, bool> {
+	struct RefinementSorter {
 		RefinementSorter(const BaseSorterByReference& sorter, const Partition* pi) : m_sorter(sorter), m_pi(pi) {}
 		
 		bool operator()(RefinementPtr a, RefinementPtr b) const {
