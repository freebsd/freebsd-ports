--- src/datatypes.cpp.orig	Mon Oct 17 10:22:04 2005
+++ src/datatypes.cpp	Fri Mar 23 21:43:42 2007
@@ -52,6 +52,43 @@
 
 using namespace std;
 
+// these need to be defined early, since some gcc versions were reported to
+// complain about: specialization of
+// 'Data_< <template-parameter-1-1> >::Data_(const dimension&, BaseGDL::InitType)
+// [with Sp = SpDXXX]' after instantiation
+//
+// string, ptr, obj (cannot be INDGEN,
+// need not to be zeroed if all intialized later)
+// struct (as a separate class) as well
+template<> Data_<SpDString>::Data_(const dimension& dim_,
+				   BaseGDL::InitType iT):
+  SpDString(dim_), dd(dim.N_Elements())
+{
+  dim.Purge();
+
+  if( iT == BaseGDL::INDGEN)
+    throw GDLException("DStringGDL(dim,InitType=INDGEN) called.");
+}
+template<> Data_<SpDPtr>::Data_(const dimension& dim_,
+				BaseGDL::InitType iT):
+  SpDPtr(dim_), dd(dim.N_Elements())
+{
+  dim.Purge();
+
+  if( iT == BaseGDL::INDGEN)
+    throw GDLException("DPtrGDL(dim,InitType=INDGEN) called.");
+}
+template<> Data_<SpDObj>::Data_(const dimension& dim_,
+				BaseGDL::InitType iT):
+  SpDObj(dim_), dd(dim.N_Elements())
+{
+  dim.Purge();
+
+  if( iT == BaseGDL::INDGEN)
+    throw GDLException("DObjGDL(dim,InitType=INDGEN) called.");
+}
+
+
 // this (ugly) including of other sourcefiles has to be done, because
 // on Mac OS X a template instantiation request (see bottom of file)
 // can only be done once
@@ -518,36 +555,6 @@
 //   return true;
 // }
 
-// string, ptr, obj (cannot be INDGEN, 
-// need not to be zeroed if all intialized later)
-// struct (as a separate class) as well
-template<> Data_<SpDString>::Data_(const dimension& dim_,  
-				   BaseGDL::InitType iT): 
-  SpDString(dim_), dd(dim.N_Elements())
-{
-  dim.Purge();
-  
-  if( iT == BaseGDL::INDGEN)
-    throw GDLException("DStringGDL(dim,InitType=INDGEN) called.");
-}
-template<> Data_<SpDPtr>::Data_(const dimension& dim_,  
-				BaseGDL::InitType iT): 
-  SpDPtr(dim_), dd(dim.N_Elements())
-{
-  dim.Purge();
-  
-  if( iT == BaseGDL::INDGEN)
-    throw GDLException("DPtrGDL(dim,InitType=INDGEN) called.");
-}
-template<> Data_<SpDObj>::Data_(const dimension& dim_,  
-				BaseGDL::InitType iT): 
-  SpDObj(dim_), dd(dim.N_Elements())
-{
-  dim.Purge();
-
-  if( iT == BaseGDL::INDGEN)
-    throw GDLException("DObjGDL(dim,InitType=INDGEN) called.");
-}
 
 template<class Sp>
 const SizeT Data_<Sp>::NBytes() const 
