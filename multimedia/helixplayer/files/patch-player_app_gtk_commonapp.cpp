--- ./player/app/gtk/commonapp.cpp.orig	Thu Nov 25 00:00:23 2004
+++ ./player/app/gtk/commonapp.cpp	Sat Mar 26 14:43:51 2005
@@ -1868,7 +1868,19 @@
     {
         /* g_error will call abort */
 	g_error("Unable to open display");
-    }    
+    }
+
+#ifdef G_OS_UNIX
+    if(strcmp(hxplayer_x_init_threads, "delayed") == 0)
+    {
+        Status status;
+        status = XInitThreads();
+        if(!status)
+        {
+            g_warning("X libraries appear to have been compiled without multithreaded support.");
+        }
+    }
+#endif
 
 #ifdef G_OS_UNIX
     if(strcmp(hxplayer_x_init_threads, "after") == 0)
