--- src/polyhedralfan.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/polyhedralfan.cpp
@@ -400,10 +400,10 @@ PolyhedralFan PolyhedralFan::fullComplex()const
 
   while(1)
     {
-      log2 debug<<"looping";
+      gfan_log2 debug<<"looping";
       bool doLoop=false;
       PolyhedralFan facets=ret.facetComplex();
-      log2 debug<<"number of facets"<<facets.size()<<"\n";
+      gfan_log2 debug<<"number of facets"<<facets.size()<<"\n";
       for(PolyhedralConeList::const_iterator i=facets.cones.begin();i!=facets.cones.end();i++)
 	if(!ret.contains(*i))
 	  {
@@ -1232,7 +1232,7 @@ void addFacesToSymmetricComplex(SymmetricComplex &c, s
 
       if(!c.contains(theCone))
 	{
-	  log2
+	  gfan_log2
 	  {
 	    static int t;
 	    if((t&1023)==0)
@@ -1317,7 +1317,7 @@ SymmetricComplex PolyhedralFan::toSymmetricComplex(Sym
 		static int t;
 		log1 fprintf(Stderr,"Adding faces of cone %i\n",t++);
 	      }
-	      log2 fprintf(Stderr,"Dim: %i\n",i->dimension());
+	      gfan_log2 fprintf(Stderr,"Dim: %i\n",i->dimension());
 
 	      addFacesToSymmetricComplex(symCom,*i,i->getHalfSpaces(),generatorsOfLinealitySpace);
 	    }
@@ -1387,7 +1387,7 @@ void PolyhedralFan::printWithIndices(class Printer *p,
 	static int t;
 	log1 fprintf(Stderr,"Adding faces of cone %i\n",t++);
       }
-      log2 fprintf(Stderr,"Dim: %i\n",i->dimension());
+      gfan_log2 fprintf(Stderr,"Dim: %i\n",i->dimension());
 
       addFacesToSymmetricComplex(symCom,*i,i->getHalfSpaces(),generatorsOfLinealitySpace);
     }
@@ -1565,11 +1565,11 @@ PolyhedralFan PolyhedralFan::readFan(string const &fil
 
     PolyhedralFan ret(n);
 
-    log2 cerr<< "Number of orbits to expand "<<cones.size()<<endl;
+    gfan_log2 cerr<< "Number of orbits to expand "<<cones.size()<<endl;
     for(int i=0;i<cones.size();i++)
       if(coneIndices==0 || coneIndices->count(i))
 	{
-	  log2 cerr<<"Expanding symmetries of cone"<<endl;
+	  gfan_log2 cerr<<"Expanding symmetries of cone"<<endl;
 	  /*	  for(SymmetryGroup::ElementContainer::const_iterator perm=sym->elements.begin();perm!=sym->elements.end();perm++)
 	    {
 	      IntegerVectorList coneRays;
@@ -1851,7 +1851,7 @@ bool PolyhedralFan::isConnected(SymmetryGroup *sym)con
 
   for(PolyhedralConeList::const_iterator i=cones.begin();i!=cones.end();i++)
     {
-      log2 cerr<<"Computing ridges of facet." << endl;
+      gfan_log2 cerr<<"Computing ridges of facet." << endl;
       PolyhedralFan ridges=facetsOfCone(*i);
       IntegerVectorList interiorPoints;
       for(PolyhedralConeList::const_iterator j=ridges.cones.begin();j!=ridges.cones.end();j++)
