--- main.c.orig	2025-09-08 19:57:23 UTC
+++ main.c
@@ -37,9 +37,10 @@ static void
 
 /** alarmInterrupt is used to print out the progress at specific intervals */
 static void
-alarmInterrupt(int) {
+alarmInterrupt(int sig) {
   if(!printProgress())
     alarm(PRINTERVAL);
+  (void)sig;
 }
 
 /** autoSave is used to save down the current state when interrupted */
