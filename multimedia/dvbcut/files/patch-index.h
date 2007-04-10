--- src/index.h~	Mon Dec 19 22:52:11 2005
+++ src/index.h	Mon Dec 19 23:05:24 2005
@@ -20,7 +20,11 @@
 #define _DVBCUT_INDEX_H
 
 #include <stdint.h>
-#include <byteswap.h>
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
+#include <byteswap.h>
+#endif
 #include "types.h"
 #include "pts.h"
 #include "defines.h"
@@ -53,7 +53,7 @@
     picture(filepos_t pos, pts_t _pts, int framerate, int aspectratio,
             int sequencenumber, int picturetype, bool seqheader=false) :
         position( pos ),
-        pts((_pts&0xffffffffffffll) | ((uint64_t)( (framerate&0xf)|((aspectratio&0xf)<<4)|
+        pts((_pts&0xffffffffffll) | ((uint64_t)( (framerate&0xf)|((aspectratio&0xf)<<4)|
                                        ((sequencenumber&0x3ff)<<8)|((picturetype&0x3)<<18)|(seqheader?0x100000:0) )<<40))
       { }
     picture() : position(0), pts(0)
@@ -66,7 +66,7 @@
     pts_t getpts() const
       {
       pts_t l=pts&0xffffffffffll;
-      return (l&0x8000000000ll) ? (l|0xffffff0000000000ll):l;
+      return (l ^ 0x8000000000ll) - 0x8000000000ll;
       }
     int getframerate() const
       {
@@ -136,10 +136,10 @@
     {
     pic+=skipfirst;
     int seq=pic;
-    while (!p[seq].getseqheader())
+    while (seq > 0 && !p[seq].getseqheader())
       --seq;
     pic=pic-seq;
-    while(p[seq].getsequencenumber()!=pic)
+    while(seq < pictures && p[seq].getsequencenumber()!=pic)
       ++seq;
     return seq;
     }
