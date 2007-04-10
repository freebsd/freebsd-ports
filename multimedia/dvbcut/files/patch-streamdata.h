--- src/streamdata.h~	Sun Dec 11 21:07:37 2005
+++ src/streamdata.h	Mon Apr  9 16:55:43 2007
@@ -22,6 +22,8 @@
 #include <string>
 #include <list>
 #include <ffmpeg/avformat.h>
+
+#include "port.h"
 #include "tsfile.h"
 #include "psfile.h"
 #include "buffer.h"
@@ -106,7 +108,7 @@
   filepos_t curpos;
   const streamtype::type type;
   bool transportstream;
-  off_t nextfilepos;
+  dvbcut_off_t nextfilepos;
 
 public:
   streamdata(streamtype::type t, bool transport_stream, uint32_t buffersize=256<<10) :
@@ -194,6 +196,11 @@
       it->bufferposition=offset;
       }
     curpos=items.front().fileposition;
+    if (offset & (1ul<<31)) {
+      for(std::list<item>::iterator it=items.begin();it!=items.end();++it)
+	it->bufferposition-=offset;
+      offset=0;
+      }
     }
   void append(const void *d, int s)
     {
