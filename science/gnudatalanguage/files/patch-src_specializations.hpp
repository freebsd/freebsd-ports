Fix the build with GCC 6 (bug 219300).

Obtained from: https://sourceforge.net/p/gnudatalanguage/bugs/688/#4622
--- src/specializations.hpp.orig	2017-08-15 19:53:08 UTC
+++ src/specializations.hpp
@@ -534,16 +534,6 @@ void Data_<SpDString>::MinMax( DLong* minE, DLong* max
 
 // default_io.cpp
 template<>  
-std::istream& operator>>(std::istream& i, Data_<SpDFloat>& data_); 
-template<>  
-std::istream& operator>>(std::istream& i, Data_<SpDDouble>& data_); 
-template<>  
-std::istream& operator>>(std::istream& i, Data_<SpDComplex>& data_); 
-template<>  
-std::istream& operator>>(std::istream& i, Data_<SpDComplexDbl>& data_); 
-template<>  
-std::istream& operator>>(std::istream& is, Data_<SpDString>& data_); 
-template<>  
 std::ostream& Data_<SpDLong>::ToStream(std::ostream& o, SizeT w, SizeT* actPosPtr); 
 template<>  
 std::ostream& Data_<SpDULong>::ToStream(std::ostream& o, SizeT w, SizeT* actPosPtr); 
