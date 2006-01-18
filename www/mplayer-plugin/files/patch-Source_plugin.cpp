===================================================================
RCS file: /cvsroot/mplayerplug-in/mplayerplug-in/Source/plugin.cpp,v
retrieving revision 1.263
retrieving revision 1.264
diff -u -r1.263 -r1.264
--- Source/plugin.cpp	2005/12/12 14:05:08	1.263
+++ Source/plugin.cpp	2006/01/02 16:49:23	1.264
@@ -388,9 +388,13 @@
 		paused = 0;
 	    }
 	    sendCommand(this, "quit\n");
-    	    pthread_mutex_lock(&read_mutex);
+#ifndef BSD
+	    pthread_mutex_lock(&read_mutex);
+#endif
 	    cancelled = 1;
+#ifndef BSD
     	    pthread_mutex_unlock(&read_mutex);
+#endif
 	    pthread_mutex_unlock(&control_mutex);
 	    pthread_cancel(player_thread);
 	    pthread_join(player_thread, NULL);
