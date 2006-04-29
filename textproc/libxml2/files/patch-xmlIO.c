--- xmlIO.c.orig	Thu Apr 27 08:13:42 2006
+++ xmlIO.c	Sat Apr 29 01:27:45 2006
@@ -616,6 +616,7 @@ xmlCheckFilename (const char *path)
 	}
 #else
 #ifdef HAVE_STAT
+    {
     struct stat stat_buffer;
 
     if (stat(path, &stat_buffer) == -1)
@@ -625,6 +626,7 @@ xmlCheckFilename (const char *path)
     if (S_ISDIR(stat_buffer.st_mode))
         return 2;
 #endif /* S_ISDIR */
+    }
 #endif /* HAVE_STAT */
 #endif /* WIN32 */
 
