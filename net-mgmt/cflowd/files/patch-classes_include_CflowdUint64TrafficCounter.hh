--- ./classes/include/CflowdUint64TrafficCounter.hh.orig	Sun Feb  7 19:43:03 1999
+++ ./classes/include/CflowdUint64TrafficCounter.hh	Mon Apr  9 00:17:53 2007
@@ -49,6 +49,8 @@
 #include "caida_t.h"
 }
 
+#include <iostream>
+
 #include "ArtsPrimitive.hh"
 
 extern ArtsPrimitive g_CfdArtsPrimitive;
@@ -147,7 +149,7 @@
   //.........................................................................
   //  Reads the counter from an istream.  Returns the istream.
   //-------------------------------------------------------------------------
-  inline istream & read(istream & is)
+  inline std::istream & read(std::istream & is)
   {
     g_CfdArtsPrimitive.ReadUint64(is,this->_pkts,sizeof(this->_pkts));
     g_CfdArtsPrimitive.ReadUint64(is,this->_bytes,sizeof(this->_bytes));
@@ -190,7 +192,7 @@
   //.........................................................................
   //  Writes the counter to an ostream.  Returns the ostream.
   //-------------------------------------------------------------------------
-  inline ostream & write(ostream & os) const
+  inline std::ostream & write(std::ostream & os) const
   {
     g_CfdArtsPrimitive.WriteUint64(os,this->_pkts,sizeof(this->_pkts));
     g_CfdArtsPrimitive.WriteUint64(os,this->_bytes,sizeof(this->_bytes));
