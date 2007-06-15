--- ./classes/include/CflowdRawFlow.hh.orig	Tue Feb 29 20:32:20 2000
+++ ./classes/include/CflowdRawFlow.hh	Mon Apr  9 00:33:03 2007
@@ -1016,7 +1016,7 @@
   //.........................................................................
   //  Reads a flow from an istream.  Returns the istream.
   //-------------------------------------------------------------------------
-  istream & Read(istream & is);
+  std::istream & Read(std::istream & is);
 
   //-------------------------------------------------------------------------
   //                            int Read(int fd)
@@ -1033,7 +1033,7 @@
   //.........................................................................
   //  Writes a flow to an ostream.  Returns the ostream.
   //-------------------------------------------------------------------------
-  ostream & Write(ostream & os) const;
+  std::ostream & Write(std::ostream & os) const;
 
   //-------------------------------------------------------------------------
   //                            int Write(int fd) const
@@ -1062,7 +1062,7 @@
   //  CflowdRawFlow object to an ostream in a human-readable form.
   //  Returns the ostream.
   //-------------------------------------------------------------------------
-  friend ostream& operator << (ostream& os,
+  friend std::ostream& operator << (std::ostream& os,
                                const CflowdRawFlow & flow);
 
   //-------------------------------------------------------------------------
