--- lib_src/indexSet.cpp.orig	2013-10-01 10:15:14.000000000 +0200
+++ lib_src/indexSet.cpp	2013-10-01 10:15:03.000000000 +0200
@@ -390,3 +390,7 @@
 
 template class indexSetComplement<unsigned short>;
 template class indexSetComplement<unsigned long>;
+template indexSet<unsigned long>::indexSet(unsigned long, goblinController &);
+template indexSet<unsigned long>::~indexSet();
+template indexSet<unsigned short>::indexSet(unsigned short, goblinController &);
+template indexSet<unsigned short>::~indexSet();
