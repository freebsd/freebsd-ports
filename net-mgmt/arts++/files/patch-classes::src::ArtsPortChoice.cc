--- ./classes/src/ArtsPortChoice.cc.orig	Mon Oct  2 13:05:26 2000
+++ ./classes/src/ArtsPortChoice.cc	Wed Sep 25 16:38:10 2002
@@ -293,7 +293,7 @@
 {
   uint8_t   portLength;
 
-  is.read(&this->_flags,sizeof(this->_flags));
+  is.read((char *)&this->_flags,sizeof(this->_flags));
   if (!is)
     return(is);
   
@@ -364,7 +364,7 @@
 {
   uint8_t  portLength;
   
-  os.write(&this->_flags,sizeof(this->_flags));
+  os.write((char *)&this->_flags,sizeof(this->_flags));
 
   portLength = 1;
   if (this->_flags & this->k_firstPortLengthMask)
