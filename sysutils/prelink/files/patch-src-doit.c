diff -Nur src/doit.c src/doit.c
--- src/doit.c	2013-02-19 23:54:34.000000000 +0200
+++ src/doit.c	2013-02-19 23:50:31.000000000 +0200
@@ -16,7 +16,9 @@
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #include <config.h>
+#if HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 #include <errno.h>
 #include <error.h>
 #include <fcntl.h>
@@ -51,7 +53,11 @@
 {
   int i, j;
   DSO *dso;
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
   struct prelink_link *hardlink;
   char *move = NULL;
   size_t movelen = 0;
@@ -109,7 +115,11 @@
   if (dso == NULL)
     goto error_out;
 
+#if __LINUX__
   if (fstat64 (dso->fd, &st) < 0)
+#else
+  if (fstat (dso->fd, &st) < 0)
+#endif
     {
       error (0, errno, "%s changed during prelinking", ent->filename);
       goto error_out;
@@ -145,7 +155,11 @@
     {
       size_t len;
 
+#if __LINUX__
       if (lstat64 (hardlink->canon_filename, &st) < 0)
+#else
+      if (lstat (hardlink->canon_filename, &st) < 0)
+#endif
 	{
 	  error (0, 0, "Could not stat %s (former hardlink to %s)",
 		 hardlink->canon_filename, ent->canon_filename);
@@ -186,7 +200,7 @@
 	    }
 	}
 
-      memcpy (mempcpy (move, hardlink->canon_filename, len), ".#prelink#",
+      memcpy (memcpy (move, hardlink->canon_filename, len) + len, ".#prelink#",
 	      sizeof (".#prelink#"));
       if (rename (hardlink->canon_filename, move) < 0)
 	{
@@ -216,7 +230,11 @@
     }
   free (move);
 
+#if __LINUX__
   if (! dry_run && stat64 (ent->canon_filename, &st) >= 0)
+#else
+  if (! dry_run && stat (ent->canon_filename, &st) >= 0)
+#endif
     {
       ent->dev = st.st_dev;
       ent->ino = st.st_ino;
