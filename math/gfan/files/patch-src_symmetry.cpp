--- src/symmetry.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/symmetry.cpp
@@ -631,7 +631,7 @@ void SymmetryGroup::createTrie()
 	int I=0;
 	for(ElementContainer::const_iterator i=elements.begin();i!=elements.end();i++,I++)
 		trie->insert(*i,I);
-	log2 debug<<"Number of elements";log2 debug.printInteger(trie->size());log2 debug<<"\n";
+	gfan_log2 debug<<"Number of elements";gfan_log2 debug.printInteger(trie->size());gfan_log2 debug<<"\n";
 	log1 debug<<"Done creating symmetry trie.\n";
 
 	if(0)
