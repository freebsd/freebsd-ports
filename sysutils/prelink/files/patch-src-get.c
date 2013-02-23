diff -Nur src/get.c src/get.c
--- src/get.c	2013-02-19 23:54:34.000000000 +0200
+++ src/get.c	2013-02-19 23:50:31.000000000 +0200
@@ -163,9 +163,17 @@
 
 	  if (hardlink == NULL)
 	    {
+#if __LINUX__
 	      struct stat64 st;
+#else
+	      struct stat st;
+#endif
 
+#if __LINUX__
 	      if (stat64 (filename, &st) < 0)
+#else
+	      if (stat (filename, &st) < 0)
+#endif
 		{
 		  error (0, errno, "%s: Could not stat %s",
 			 info->ent->filename, filename);
