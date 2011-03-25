--- ksysguardd.c	2011-03-17 20:50:04.000000000 +0200
+++ ksysguardd.c	2011-01-30 10:30:11.000000000 +0200
@@ -392,6 +392,7 @@
   return highestFD;
 }
 
+#ifdef HAVE_SYS_INOTIFY_H
 static void checkModules()
 {
   struct SensorModul *entry;
@@ -400,6 +401,7 @@
     if ( entry->checkCommand != NULL && entry->available )
       entry->checkCommand();
 }
+#endif
 
 static void handleSocketTraffic( int socketNo, const fd_set* fds )
 {
