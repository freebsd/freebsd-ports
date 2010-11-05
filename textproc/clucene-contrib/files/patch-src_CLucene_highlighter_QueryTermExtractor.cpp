--- src/CLucene/highlighter/QueryTermExtractor.cpp	Sat Feb 10 13:56:34 2007
+++ src/CLucene/highlighter/QueryTermExtractor.cpp.orig	Mon Nov 20 13:35:09 2006
@@ -79,9 +79,9 @@
 
 	void QueryTermExtractor::getTermsFromBooleanQuery(const BooleanQuery * query, WeightedTermList * terms, bool prohibited)
 	{
-		// TODO: change Query to get the queryclauses and their number in one function call
-		BooleanClause** queryClauses = query->getClauses();
 		uint32_t numClauses = query->getClauseCount();
+		BooleanClause** queryClauses = _CL_NEWARRAY(BooleanClause*,numClauses);
+		query->getClauses(queryClauses);
 
 		for (uint32_t i = 0; i < numClauses; i++)
 		{
