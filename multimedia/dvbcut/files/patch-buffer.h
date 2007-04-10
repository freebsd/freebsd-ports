--- src/buffer.h~	Sun Dec 11 21:26:21 2005
+++ src/buffer.h	Mon Apr  9 16:55:43 2007
@@ -19,6 +19,8 @@
 #ifndef _DVBCUT_BUFFER_H_
 #define _DVBCUT_BUFFER_H_
 
+#include "port.h"
+
 class buffer
   {
 protected:
@@ -144,9 +146,9 @@
   int fd;
   bool close;
   bool eof;
-  off_t pos;
-  off_t needseek;
-  off_t filesize;
+  dvbcut_off_t pos;
+  dvbcut_off_t needseek;
+  dvbcut_off_t filesize;
   bool filesizechecked;
   bool mmapped;
   static long pagesize;
@@ -158,6 +160,7 @@
   inbuffer(inbuffer &b, unsigned int _size=0, unsigned int mmapsize=0);
   ~inbuffer();
   int open(const char *filename);
+  bool statfilesize(dvbcut_off_t& _size) const;
 
   const void *data() const
     {
@@ -201,13 +204,13 @@
     {
     needseek=-(1ll<<61);
     }
-  off_t getfilesize()
+  dvbcut_off_t getfilesize()
     {
     if (!filesizechecked)
       checkfilesize();
     return filesize;
     }
-  off_t getfilepos() const
+  dvbcut_off_t getfilepos() const
     {
     return pos+readpos;
     }
