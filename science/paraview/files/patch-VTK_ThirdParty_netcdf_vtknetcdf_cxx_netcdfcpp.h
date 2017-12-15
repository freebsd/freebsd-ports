--- VTK/ThirdParty/netcdf/vtknetcdf/cxx/netcdfcpp.h.orig	2016-11-14 15:41:57 UTC
+++ VTK/ThirdParty/netcdf/vtknetcdf/cxx/netcdfcpp.h
@@ -21,17 +21,17 @@
 typedef const char* NcToken;    // names for netCDF objects
 typedef unsigned int NcBool;    // many members return 0 on failure
 
-class MSCPP_EXTRA NcDim;        // dimensions
-class MSCPP_EXTRA NcVar;        // variables
-class MSCPP_EXTRA NcAtt;        // attributes
-class MSCPP_EXTRA NcError;
+class NcDim;        // dimensions
+class NcVar;        // variables
+class NcAtt;        // attributes
+class NcError;
 
 /*
  * ***********************************************************************
  * A netCDF file.
  * ***********************************************************************
  */
-class MSCPP_EXTRA NcFile
+class NcFile
 {
   public:
 
@@ -146,7 +146,7 @@ class MSCPP_EXTRA NcFile
  * of an open netCDF file.
  * **********************************************************************
  */
-class MSCPP_EXTRA NcDim
+class NcDim
 {
   public:
     NcToken name( void ) const;
@@ -178,7 +178,7 @@ class MSCPP_EXTRA NcDim
  * components of an open netCDF file.
  * **********************************************************************
  */
-class MSCPP_EXTRA NcTypedComponent
+class NcTypedComponent
 {
   public:
     virtual ~NcTypedComponent( void ) {}
@@ -216,7 +216,7 @@ class MSCPP_EXTRA NcTypedComponent
  * a shape, given by a list of dimensions
  * **********************************************************************
  */
-class MSCPP_EXTRA NcVar : public NcTypedComponent
+class NcVar : public NcTypedComponent
 {
   public:
     virtual ~NcVar( void );
@@ -414,7 +414,7 @@ class MSCPP_EXTRA NcVar : public NcTyped
  * associated with a specific variable, or are global to the file.
  * **********************************************************************
  */
-class MSCPP_EXTRA NcAtt : public NcTypedComponent
+class NcAtt : public NcTypedComponent
 {
   public:          
     virtual ~NcAtt( void );
@@ -447,7 +447,7 @@ class MSCPP_EXTRA NcAtt : public NcTyped
  * which time the previous error-handling behavior is restored.
  * **********************************************************************
  */
-class MSCPP_EXTRA NcError {
+class NcError {
   public:
     enum Behavior {
         silent_nonfatal = 0,
