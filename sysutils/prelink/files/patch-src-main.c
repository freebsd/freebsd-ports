diff -Nur src/main.c src/main.c
--- src/main.c	2013-02-19 23:54:34.000000000 +0200
+++ src/main.c	2013-02-19 23:50:31.000000000 +0200
@@ -403,10 +403,18 @@
 
 	      if (!dso_is_rdwr (dso))
 		{
+#if __LINUX__
 		  struct stat64 st;
+#else
+		  struct stat st;
+#endif
 		  int err;
 
+#if __LINUX__
 		  if (fstat64 (dso->fd, &st) < 0)
+#else
+		  if (fstat (dso->fd, &st) < 0)
+#endif
 		    {
 		      error (0, errno, "Could not stat %s", dso->filename);
 		      ++failures;
