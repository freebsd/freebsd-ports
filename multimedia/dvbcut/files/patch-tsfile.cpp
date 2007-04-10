--- src/tsfile.cpp~	Wed Dec 14 22:52:10 2005
+++ src/tsfile.cpp	Mon Apr  9 16:55:43 2007
@@ -16,6 +16,7 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+#include "port.h"
 #include "tsfile.h"
 #include "streamhandle.h"
 #include <list>
@@ -38,6 +39,11 @@
   std::list<std::pair<int,int> > audios;
   for(int i=0;i<inpackets;++i) {
     const tspacket &p=((const tspacket*)buf.data())[i];
+    if (p.transport_error_indicator())
+      continue;	// drop invalid packet --mr
+    int pid=p.pid();
+    if (apid[pid])
+      continue;	// already had this pid --mr
     int sid=p.sid();
     if (sid<0)
       continue;
@@ -48,17 +54,16 @@
     //         sid=payload[9+payload[8]] | ((sid==0xbd)?0x100:0x200);
     //       }
 
-    int pid=p.pid();
-    if (((sid&0xe0) == 0xc0)&&(apid[pid]==false)) // mpeg audio stream
+    if ((sid&0xe0) == 0xc0) // mpeg audio stream
       {
       audios.push_back(std::pair<int,int>(sid,pid));
       apid[pid]=true;
-      } else if ((sid==0xbd) && (apid[pid]==false)) // private stream 1, possibly AC3 audio stream
+      } else if (sid==0xbd) // private stream 1, possibly AC3 audio stream
       {
       const uint8_t *payload=(const uint8_t*) p.payload();
       //       if (p.payload_length()>9+payload[8])
       //         sid=payload[9+payload[8]] | ((sid==0xbd)?0x100:0x200);
-      if ((p.payload_length()>=11) && (p.payload_length()>9+payload[8]) &&
+      if ((p.payload_length()>=9) && (p.payload_length()>=11+payload[8]) &&
           (*(uint16_t*)&payload[9+payload[8]]==mbo16(0xb77)) )
         {
         audios.push_back(std::pair<int,int>(sid,pid));
@@ -111,7 +116,7 @@
   bool lostsync(false);
 
   for(;;) {
-    off_t packetpos=s.fileposition;
+    dvbcut_off_t packetpos=s.fileposition;
       {
       int pd=buf.providedata(TSPACKETSIZE,packetpos);
       if (pd<0)
@@ -154,6 +159,9 @@
 
     s.fileposition+=TSPACKETSIZE;
 
+    // Abandon invalid packets --mr
+    if (p->transport_error_indicator())
+      continue;
     // Abandon packets which have no payload or have invalid adaption field length
     if (p->payload_length()<=0)
       continue;
