--- dj3320.cpp.orig	2005-08-22 18:47:00 UTC
+++ dj3320.cpp
@@ -400,7 +400,7 @@ DISPLAY_STATUS DJ3320::ParseError (BYTE 
 {
     DRIVER_ERROR err = NO_ERROR;
     BYTE byDevIDBuffer[DevIDBuffSize];
-    char *pcStr = NULL;
+    const char *pcStr = NULL;
     BYTE byStatus1, byStatus2;
 
     memset(byDevIDBuffer, 0, sizeof(byDevIDBuffer));
