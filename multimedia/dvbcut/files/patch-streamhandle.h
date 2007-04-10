--- src/streamhandle.h~	Sun Dec 11 21:06:43 2005
+++ src/streamhandle.h	Mon Apr  9 16:55:43 2007
@@ -19,15 +19,16 @@
 #ifndef _DVBCUT_STREAMHANDLE_H
 #define _DVBCUT_STREAMHANDLE_H
 
+#include "port.h"
 #include "mpgfile.h"
 #include "streamdata.h"
 
 struct streamhandle
   {
-  off_t fileposition;
+  dvbcut_off_t fileposition;
   streamdata *stream[MAXAVSTREAMS];
 
-  streamhandle(off_t filepos=0) : fileposition(filepos), stream()
+  streamhandle(dvbcut_off_t filepos=0) : fileposition(filepos), stream()
     {}
   ~streamhandle()
     {
