--- ./classes/include/CflowdAsMatrix.hh.orig	Mon Sep 21 18:31:43 1998
+++ ./classes/include/CflowdAsMatrix.hh	Mon Apr  9 14:02:43 2007
@@ -55,7 +55,7 @@
 #include "CflowdAsMatrixTrafficCounter.hh"
 #include "CflowdRawFlow.hh"
 
-typedef  map<CflowdAsMatrixKey, CflowdAsMatrixTrafficCounter, less<CflowdAsMatrixKey> >   CflowdAsMatrixMap_t;
+typedef  std::map<CflowdAsMatrixKey, CflowdAsMatrixTrafficCounter, std::less<CflowdAsMatrixKey> >   CflowdAsMatrixMap_t;
 
 //---------------------------------------------------------------------------
 //  class CflowdAsMatrix : public CflowdAsMatrixMap_t
@@ -70,7 +70,7 @@
 class CflowdAsMatrix : public CflowdAsMatrixMap_t
 {
 public:
-  typedef CflowdAsMatrixMap_t::iterator        iterator;
+  typedef CflowdAsMatrixMap_t::iterator        std::iterator;
   typedef CflowdAsMatrixMap_t::const_iterator  const_iterator;
 
   //-------------------------------------------------------------------------
@@ -87,7 +87,7 @@
   //  Reads the contents of a CflowdAsMatrix from an istream.  Returns
   //  the istream.
   //-------------------------------------------------------------------------
-  istream & read(istream & is);
+  std::istream & read(std::istream & is);
   
   //-------------------------------------------------------------------------
   //                            int read(int fd)
@@ -103,7 +103,7 @@
   //  Writes the contents of a CflowdAsMatrix to an ostream.  Returns
   //  the ostream.
   //-------------------------------------------------------------------------
-  ostream & write(ostream & os) const;
+  std::ostream & write(std::ostream & os) const;
   
   //-------------------------------------------------------------------------
   //                         int write(int fd) const
