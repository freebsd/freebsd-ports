--- src/include/biosem.h.orig	2014-04-24 18:05:44 UTC
+++ src/include/biosem.h
@@ -26,7 +26,7 @@ typedef struct {
 	UINT32 eventType;
 	BYTE   digest[20];
 	UINT32 eventDataSize;
-	BYTE   event[0];/* (eventSize) bytes of event data follows */
+	BYTE   event[1];/* (eventSize) bytes of event data follows */
 } TCG_PCClientPCREventStruc;
 
 #define EVLOG_SOURCE_BIOS	1
