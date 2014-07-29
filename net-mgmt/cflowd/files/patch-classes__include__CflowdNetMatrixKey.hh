--- classes/include/CflowdNetMatrixKey.hh.orig	Fri Jun 15 16:36:13 2007
+++ classes/include/CflowdNetMatrixKey.hh	Fri Jun 15 16:45:41 2007
@@ -53,8 +53,10 @@
 }
 
 #include <map>
+#include <strstream>
 
 #include "ArtsPrimitive.hh"
+using namespace std;
 
 extern ArtsPrimitive g_CfdArtsPrimitive;
 
@@ -191,9 +193,9 @@
   inline istream & read(istream & is)
   {
     g_CfdArtsPrimitive.ReadIpv4Network(is,this->_src,sizeof(this->_src));
-    is.read(&(this->_srcMaskLen),sizeof(this->_srcMaskLen));
+    is.read((char *)&(this->_srcMaskLen),sizeof(this->_srcMaskLen));
     g_CfdArtsPrimitive.ReadIpv4Network(is,this->_dst,sizeof(this->_dst));
-    is.read(&(this->_dstMaskLen),sizeof(this->_dstMaskLen));
+    is.read((char *)&(this->_dstMaskLen),sizeof(this->_dstMaskLen));
     
     return(is);
   }
@@ -263,9 +265,9 @@
   inline ostream & write(ostream & os) const
   {
     g_CfdArtsPrimitive.WriteIpv4Network(os,this->_src,sizeof(this->_src));
-    os.write(&(this->_srcMaskLen),sizeof(this->_srcMaskLen));
+    os.write((char *)&(this->_srcMaskLen),sizeof(this->_srcMaskLen));
     g_CfdArtsPrimitive.WriteIpv4Network(os,this->_dst,sizeof(this->_dst));
-    os.write(&(this->_dstMaskLen),sizeof(this->_dstMaskLen));
+    os.write((char *)&(this->_dstMaskLen),sizeof(this->_dstMaskLen));
     return(os);
   }
   
