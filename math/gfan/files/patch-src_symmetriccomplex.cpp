--- src/symmetriccomplex.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/symmetriccomplex.cpp
@@ -509,7 +509,7 @@ bool SymmetricComplex::isPure()const
   int dim=-1;
   for(ConeContainer::const_iterator i=cones.begin();i!=cones.end();i++)
     {
-      log2{static int a;if(!((a++)&63))fprintf(Stderr,"%i\n",a);}//log0
+      gfan_log2{static int a;if(!((a++)&63))fprintf(Stderr,"%i\n",a);}//log0
     if(isMaximal(*i))
       {
 	int dim2=i->dimension;
