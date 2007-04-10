--- src/buffer.cpp~	Sun Dec 11 21:27:04 2005
+++ src/buffer.cpp	Mon Apr  9 16:55:43 2007
@@ -26,8 +26,18 @@
 #include <stdlib.h>
 // #include <stdio.h>
 #include <stdint.h>
+
+#include "port.h"
 #include "buffer.h"
 
+#ifndef O_BINARY
+#define O_BINARY    0
+#endif /* O_BINARY */
+
+#ifndef MAP_FAILED
+#define MAP_FAILED	((void*)-1)
+#endif
+
 buffer::buffer(unsigned int _size):size(_size), readpos(0), writepos(0), wrtot(0)
   {
   if (size > 0)
@@ -171,8 +181,8 @@
     writepos=size;
     if (pos+writepos>filesize)
       writepos=filesize-pos;
-    d=::mmap(0,writepos,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,pos);
-    if (!d) {
+    d=::mmap(0,writepos,PROT_READ,MAP_SHARED,fd,pos);
+    if (d==MAP_FAILED) {
       size=_size;
       mmapped=false;
       } else
@@ -227,7 +237,7 @@
 
   close=true;
   needseek=0;
-  fd=::open(filename,O_RDONLY);
+  fd=::open(filename,O_RDONLY|O_BINARY);
   if (fd<0)
     return fd;
 
@@ -236,20 +246,33 @@
   return fd;
   }
 
+bool inbuffer::statfilesize(dvbcut_off_t& _size) const
+  {
+#ifdef __WIN32__
+  struct _stati64 st;
+  if ((::_fstati64(fd,&st)==0)&&(S_ISREG(st.st_mode))) {
+#else /* __WIN32__ */
+  struct stat st;
+  if ((::fstat(fd,&st)==0)&&(S_ISREG(st.st_mode))) {
+#endif /* __WIN32__ */
+	_size=st.st_size;
+	return true;
+	}
+  return false;
+  }
+
 void inbuffer::setup()
   {
   unsigned int _size=size;
-  struct stat st;
 
-  if ((::fstat(fd,&st)==0)&&(S_ISREG(st.st_mode))) {
+  if (statfilesize(filesize)) {
     filesizechecked=true;
-    filesize=st.st_size;
     if (mmapsize>0)
       size=mmapsize;
     if (size>filesize)
       size=filesize;
-    d=::mmap(0,size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
-    if (!d) {
+    d=::mmap(0,size,PROT_READ,MAP_SHARED,fd,0);
+    if (d==MAP_FAILED) {
       size=_size;
       mmapped=false;
       } else {
@@ -295,12 +318,13 @@
         pos+=pagesize;
         if (pos<0)
           pos=0;
+        readpos=position-pos;
         }
       writepos=filesize-pos;
 
       }
-    d=::mmap(0,writepos,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,pos);
-    if (!d) {
+    d=::mmap(0,writepos,PROT_READ,MAP_SHARED,fd,pos);
+    if (d==MAP_FAILED) {
       readpos=writepos=0;
       d=malloc(size);
       mmapped=false;
@@ -368,7 +392,7 @@
 int outbuffer::open(const char* filename)
   {
   close=true;
-  return fd=::open(filename,O_WRONLY|O_CREAT|O_TRUNC);
+  return fd=::open(filename,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY);
   }
 
 int outbuffer::putdata(const void *data, unsigned int len, bool autoresize)
