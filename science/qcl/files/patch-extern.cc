--- extern.cc.orig	2014-03-27 17:24:43.000000000 +0400
+++ extern.cc	2014-09-04 21:37:03.000000000 +0400
@@ -81,7 +81,7 @@
   dim=(1 << n);
   if(!loc->getRef(sdec(dim-1,"u%ld")+sdec(dim-1)) || loc->getRef(string("u")+sdec(dim)+sdec(dim)))
     EXTERR("illegal register size for matrix operator");
-  tComplex u[dim][dim];
+  std::vector<std::vector<tComplex> > u(dim, std::vector<tComplex>(dim));
   term* t[dim];
   for(i=0;i<dim;i++) for(j=0;j<dim;j++) {
     v=loc->getVal(sdec(j,"u%ld")+sdec(i));
@@ -190,7 +190,7 @@
     EXTERR("illegal register size for permutation operator");
   int p[dim];
   int pp[dim];
-  term t[dim];
+  std::vector<term> t(dim);
   for(i=0;i<dim;i++) {
     v=loc->getVal(sdec(i,"p%ld"));
     if(!v.isInt() || v.toInt() < 0 || v.toInt() >= dim) 
@@ -207,7 +207,7 @@
       t[i]=term(bitvec(n,p[i]),1);
     }
   }
-  opPermutation(n,t).apply(*q);
+  opPermutation(n,t.data()).apply(*q);
   return 0;
 }
 
@@ -221,7 +221,7 @@
   if(dim!=v.dim())
     EXTERR("illegal register size for permutation operator");
   int p[dim];
-  term t[dim];
+  std::vector<term> t(dim);
   for(i=0;i<dim;i++) p[i]=-1;
   for(i=0;i<dim;i++) p[v[i].toInt()]=i;
   for(i=0;i<dim;i++) {
@@ -232,7 +232,7 @@
       t[i]=term(bitvec(n,v[i].toInt()),1);
     }
   }
-  opPermutation(n,t).apply(*q);
+  opPermutation(n,t.data()).apply(*q);
   return 0;
 }
 
