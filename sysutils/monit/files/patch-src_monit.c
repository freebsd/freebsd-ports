--- src/monit.c.orig	2015-06-08 12:24:39 UTC
+++ src/monit.c
@@ -819,6 +819,8 @@ static void version() {
  * M/Monit heartbeat thread
  */
 static void *heartbeat(void *args) {
+        sigset_t ns;
+        set_signal_block(&ns, NULL);
         LogInfo("M/Monit heartbeat started\n");
         LOCK(heartbeatMutex)
         {
