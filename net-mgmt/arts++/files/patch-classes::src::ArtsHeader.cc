--- ./classes/src/ArtsHeader.cc.orig	Mon Oct  2 13:05:24 2000
+++ ./classes/src/ArtsHeader.cc	Wed Sep 25 16:38:10 2002
@@ -135,23 +135,23 @@
   uint32_t  uIntDatum, idAndVersion;
   
   uShortDatum = htons(this->_magic);
-  os.write(&uShortDatum,sizeof(uShortDatum));
+  os.write((char *)&uShortDatum,sizeof(uShortDatum));
 
   idAndVersion = (this->_identifier << 4) | this->_version;
   uIntDatum = htonl(idAndVersion);
-  os.write(&uIntDatum,sizeof(uIntDatum));
+  os.write((char *)&uIntDatum,sizeof(uIntDatum));
   
   uIntDatum = htonl(this->_flags);
-  os.write(&uIntDatum,sizeof(uIntDatum));
+  os.write((char *)&uIntDatum,sizeof(uIntDatum));
   
   uShortDatum = htons(this->_numAttributes);
-  os.write(&uShortDatum,sizeof(uShortDatum));
+  os.write((char *)&uShortDatum,sizeof(uShortDatum));
   
   uIntDatum = htonl(this->_attrLength);
-  os.write(&uIntDatum,sizeof(uIntDatum));
+  os.write((char *)&uIntDatum,sizeof(uIntDatum));
   
   uIntDatum = htonl(this->_dataLength);
-  os.write(&uIntDatum,sizeof(uIntDatum));
+  os.write((char *)&uIntDatum,sizeof(uIntDatum));
 
   return(os);
 }
@@ -225,13 +225,13 @@
   uint32_t  uIntDatum;
   uint32_t  idAndVersion;
   
-  is.read(&uShortDatum,sizeof(uShortDatum));
+  is.read((char *)&uShortDatum,sizeof(uShortDatum));
   if (is.eof())
     return(is);
   
   this->_magic = ntohs(uShortDatum);
 
-  is.read(&uIntDatum,sizeof(uIntDatum));
+  is.read((char *)&uIntDatum,sizeof(uIntDatum));
   if (is.eof())
     return(is);
   
@@ -239,22 +239,22 @@
   this->_identifier = idAndVersion >> 4;
   this->_version    = idAndVersion & 0x0f;
 
-  is.read(&uIntDatum,sizeof(uIntDatum));
+  is.read((char *)&uIntDatum,sizeof(uIntDatum));
   if (is.eof())
     return(is);  
   this->_flags = ntohl(uIntDatum);
 
-  is.read(&uShortDatum,sizeof(uShortDatum));
+  is.read((char *)&uShortDatum,sizeof(uShortDatum));
   if (is.eof())
     return(is);
   this->_numAttributes = ntohs(uShortDatum);
 
-  is.read(&uIntDatum,sizeof(uIntDatum));
+  is.read((char *)&uIntDatum,sizeof(uIntDatum));
   if (is.eof())
     return(is);
   this->_attrLength = ntohl(uIntDatum);
 
-  is.read(&uIntDatum,sizeof(uIntDatum));
+  is.read((char *)&uIntDatum,sizeof(uIntDatum));
   if (is.eof())
     return(is);
   this->_dataLength = ntohl(uIntDatum);
