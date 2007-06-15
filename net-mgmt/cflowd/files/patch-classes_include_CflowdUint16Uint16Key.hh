--- ./classes/include/CflowdUint16Uint16Key.hh.orig	Wed Aug 11 18:11:35 1999
+++ ./classes/include/CflowdUint16Uint16Key.hh	Mon Apr  9 00:03:09 2007
@@ -52,6 +52,7 @@
 }
 
 #include <map>
+#include <iostream>
 
 #include "ArtsPrimitive.hh"
 
@@ -136,7 +137,7 @@
   //.........................................................................
   //  Reads the key from an istream.  Returns the istream.
   //-------------------------------------------------------------------------
-  inline istream & read(istream & is)
+  inline std::istream & read(std::istream & is)
   {
     g_CfdArtsPrimitive.ReadUint16(is,this->_src,sizeof(this->_src));
     g_CfdArtsPrimitive.ReadUint16(is,this->_dst,sizeof(this->_dst));
@@ -177,7 +178,7 @@
   //.........................................................................
   //  Writes the key to an ostream.  Returns the ostream.
   //-------------------------------------------------------------------------
-  inline ostream & write(ostream & os) const
+  inline std::ostream & write(std::ostream & os) const
   {
     g_CfdArtsPrimitive.WriteUint16(os,this->_src,sizeof(this->_src));
     g_CfdArtsPrimitive.WriteUint16(os,this->_dst,sizeof(this->_dst));
