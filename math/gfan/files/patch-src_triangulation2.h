--- src/triangulation2.h.orig	2017-06-20 14:47:37 UTC
+++ src/triangulation2.h
@@ -602,7 +602,7 @@ using namespace std;
 /*    void flip(IntegerVector const &normal)
     {
       AsciiPrinter P(Stderr);
-      log2 print(P);
+      gfan_log2 print(P);
       //log0 P.printVector(normal);
       int n=normal.size();
       //      IntegerVectorList l=wallRemoveScaledInequalities(inequalities());// This is not needed - one circuit should be enough
@@ -610,7 +610,7 @@ using namespace std;
       for(IntegerVectorList::const_iterator i=l.begin();i!=l.end();i++)
 	if(dependent(*i,normal))
 	  {
-	    log2 AsciiPrinter(Stderr).printVector(*i);
+	    gfan_log2 AsciiPrinter(Stderr).printVector(*i);
 	    for(int k=0;k<normal.size();k++)
 	      if((*i)[k]<0)
 		{
