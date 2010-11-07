--- src/include/biosem.h.orig	2010-03-12 05:22:36.000000000 +0900
+++ src/include/biosem.h	2010-10-24 21:04:04.820558727 +0900
@@ -26,7 +26,7 @@
 	UINT32 eventType;
 	BYTE   digest[20];
 	UINT32 eventDataSize;
-	BYTE   event[0];/* (eventSize) bytes of event data follows */
+	BYTE   event[1];/* (eventSize) bytes of event data follows */
 } TCG_PCClientPCREventStruc;
 
 #define EVLOG_SOURCE_BIOS	1
