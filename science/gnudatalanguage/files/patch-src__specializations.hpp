--- src/specializations.hpp.orig	Mon Oct 17 10:22:04 2005
+++ src/specializations.hpp	Fri Mar 23 22:11:15 2007
@@ -237,6 +237,12 @@
 Data_<SpDByte>* Data_<SpDComplexDbl>::LogNeg();
 
 // datatypes.cpp
+template<>
+Data_<SpDString>::Data_(const dimension& dim_, BaseGDL::InitType iT);
+template<>
+Data_<SpDPtr>::Data_(const dimension& dim_, BaseGDL::InitType iT);
+template<>
+Data_<SpDObj>::Data_(const dimension& dim_, BaseGDL::InitType iT);
 template<>  const SizeT Data_<SpDString>::NBytes() const;
 template<>  const SizeT Data_<SpDObj>::NBytes() const;
 template<>  const SizeT Data_<SpDPtr>::NBytes() const;
