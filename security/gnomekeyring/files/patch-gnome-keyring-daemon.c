--- gnome-keyring-daemon.c.orig	Tue Jul 20 22:41:27 2004
+++ gnome-keyring-daemon.c	Tue Jul 20 22:43:03 2004
@@ -121,7 +121,7 @@
 	int i;
 
 	got_random = FALSE;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	{
 		int fd;
 
@@ -352,6 +352,22 @@
 			app_ref->pathname[len] = 0;
 		}
 		
+	}
+#elif defined(__FreeBSD__)
+	{
+		char buffer[1024];
+		int len;
+		char *path;
+
+		path = g_strdup_printf ("/proc/%d/file", pid);
+		len = readlink (path, buffer, sizeof (buffer));
+		g_free (path);
+
+		if (len > 0) {
+			app_ref->pathname = g_malloc (len + 1);
+			memcpy (app_ref->pathname, buffer, len);
+			app_ref->pathname[len] = 0;
+		}
 	}
 #endif
 
