--- Source/mplayerplug-in.c.orig	Fri Oct  3 10:54:52 2003
+++ Source/mplayerplug-in.c	Sun Oct  5 02:45:25 2003
@@ -28,7 +28,7 @@
  */
 
 #include "mplayerplug-in.h"
-pthread_mutex_t playlist_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+pthread_mutex_t playlist_mutex;
 
 // This routine is only called when the plugin library is newer than the pluginrc file
 
@@ -71,7 +71,7 @@
     }
 
     if (config == NULL) {
-	config = fopen("/etc/mplayerplug-in.conf", "r");
+	config = fopen("%%PREFIX%%/etc/mplayerplug-in.conf", "r");
     }
 
     if (config == NULL) {
@@ -148,7 +148,7 @@
 	}
 
 	if (customtypes == NULL) {
-	    customtypes = fopen("/etc/mplayerplug-in.types", "r");
+	    customtypes = fopen("%%PREFIX%%/etc/mplayerplug-in.types", "r");
 	}
 
 	if (customtypes != NULL) {
@@ -274,6 +274,7 @@
     char parse[1000];
     char logfile[1000];
     char *cp;
+    pthread_mutexattr_t attr;
 
     if (instance == NULL)
 	return NPERR_INVALID_INSTANCE_ERROR;
@@ -281,6 +282,9 @@
     instance->pdata = NPN_MemAlloc(sizeof(PluginInstance));
     This = (PluginInstance *) instance->pdata;
     InitPrivateData(instance);
+    pthread_mutexattr_init(&attr);
+    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
+    pthread_mutex_init(&playlist_mutex, &attr);
 
     DESTROYED = 0;
 
