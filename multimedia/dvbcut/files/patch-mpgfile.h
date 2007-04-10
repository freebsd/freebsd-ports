--- src/mpgfile.h~	Sun Dec 11 21:14:28 2005
+++ src/mpgfile.h	Mon Apr  9 16:55:43 2007
@@ -23,6 +23,8 @@
 #include <string>
 #include <vector>
 #include <list>
+
+#include "port.h"
 #include "buffer.h"
 #include "types.h"
 #include "index.h"
@@ -150,12 +152,13 @@
                int progresstotal=0, logoutput *log=0);
   void recodevideo(muxer &mux, int start, int stop, pts_t offset,
                    int progresspics=0, int progresstotal=0, logoutput *log=0);
+  void fixtimecode(uint8_t *buf, int len, pts_t pts);
 
-  off_t getfilesize()
+  dvbcut_off_t getfilesize()
     {
     return buf.getfilesize();
     }
-  off_t getfilepos() const
+  dvbcut_off_t getfilepos() const
     {
     return buf.getfilepos();
     }
