--- VTK/ThirdParty/netcdf/vtknetcdf/cxx/ncvalues.h.orig	2016-11-14 15:41:57 UTC
+++ VTK/ThirdParty/netcdf/vtknetcdf/cxx/ncvalues.h
@@ -65,7 +65,7 @@ static const double ncBad_double = NC_FI
 #define NcVal(TYPE) makename2(NcValues_,TYPE)
 
 #define NcValuesdeclare(TYPE)						      \
-class MSCPP_EXTRA NcVal(TYPE) : public NcValues				      \
+class NcVal(TYPE) : public NcValues				      \
 {									      \
   public:								      \
     NcVal(TYPE)( void );						      \
@@ -237,7 +237,7 @@ char* NcVal(TYPE)::as_string( long n ) c
     return s;								      \
 }
 
-class MSCPP_EXTRA NcValues			// ABC for value blocks
+class NcValues			// ABC for value blocks
 {
   public:
     NcValues( void );
