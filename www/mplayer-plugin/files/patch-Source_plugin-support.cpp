--- Source/plugin-support.cpp.orig	Sat Feb 18 17:05:30 2006
+++ Source/plugin-support.cpp	Sat Feb 18 17:05:58 2006
@@ -486,9 +486,13 @@ void killmplayer(nsPluginInstance * inst
     if (instance->paused == 1)
 	sendCommand(instance, "pause\n");
     sendCommand(instance, "quit\n");
+#ifndef BSD
     pthread_mutex_lock(&(instance->read_mutex));
+#endif
     instance->cancelled = 1;
+#ifndef BSD
     pthread_mutex_unlock(&(instance->read_mutex));
+#endif
 
 /*    count = 0;
     while (count < 500) {
