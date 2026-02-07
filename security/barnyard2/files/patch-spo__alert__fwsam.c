--- src/output-plugins/spo_alert_fwsam.c.orig	2018-09-24 20:29:16 UTC
+++ src/output-plugins/spo_alert_fwsam.c
@@ -115,7 +115,7 @@
 #include <sys/filio.h>
 #endif
 
-typedef int SOCKET;
+//typedef int SOCKET;
 
 #ifndef INVALID_SOCKET
 #define INVALID_SOCKET  -1
@@ -617,7 +617,8 @@ int FWsamReadLine(char *buf,unsigned lon
         p=buf;
         while(isspace(*p))
           p++;
-        if(p>buf);
+        if(p>buf)
+	;
             strcpy(buf,p);
         if(*buf)
         {
@@ -961,7 +962,7 @@ void AlertFWsam(Packet *p, void *event, 
     FWsamPacket sampacket;
     FWsamStation *station=NULL;
     FWsamList *fwsamlist;
-    SOCKET stationsocket;
+    int stationsocket;
     int i,len,deletestation,stationtry=0;
     char *encbuf,*decbuf;
     static unsigned long lastbsip[FWSAM_REPET_BLOCKS];
@@ -1387,7 +1388,7 @@ void AlertFWsam(Packet *p, void *event, 
 void FWsamCheckOut(FWsamStation *station)
 {
     FWsamPacket sampacket;
-    SOCKET stationsocket;
+    int stationsocket;
     int i,len;
     char *encbuf,*decbuf;
 
@@ -1538,7 +1539,7 @@ int FWsamCheckIn(FWsamStation *station)
     int i,len,stationok=TRUE;
     FWsamPacket sampacket;
     char *encbuf,*decbuf;
-    SOCKET stationsocket;
+    int stationsocket;
 
 
     /* create a socket for the station */
