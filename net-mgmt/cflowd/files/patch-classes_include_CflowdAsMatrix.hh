--- classes/include/CflowdAsMatrix.hh.orig	2008-04-08 21:29:31.000000000 +0200
+++ classes/include/CflowdAsMatrix.hh	2008-04-08 21:31:22.000000000 +0200
@@ -55,7 +55,9 @@
 #include "CflowdAsMatrixTrafficCounter.hh"
 #include "CflowdRawFlow.hh"
 
-typedef  map<CflowdAsMatrixKey, CflowdAsMatrixTrafficCounter, less<CflowdAsMatrixKey> >   CflowdAsMatrixMap_t;
+class iterator;
+
+typedef  std::map<CflowdAsMatrixKey, CflowdAsMatrixTrafficCounter, std::less<CflowdAsMatrixKey> >   CflowdAsMatrixMap_t;
 
 //---------------------------------------------------------------------------
 //  class CflowdAsMatrix : public CflowdAsMatrixMap_t
@@ -87,7 +89,7 @@
   //  Reads the contents of a CflowdAsMatrix from an istream.  Returns
   //  the istream.
   //-------------------------------------------------------------------------
-  istream & read(istream & is);
+  std::istream & read(std::istream & is);
   
   //-------------------------------------------------------------------------
   //                            int read(int fd)
@@ -103,7 +105,7 @@
   //  Writes the contents of a CflowdAsMatrix to an ostream.  Returns
   //  the ostream.
   //-------------------------------------------------------------------------
-  ostream & write(ostream & os) const;
+  std::ostream & write(std::ostream & os) const;
   
   //-------------------------------------------------------------------------
   //                         int write(int fd) const
