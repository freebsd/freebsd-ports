diff -Nur src/undoall.c src/undoall.c
--- src/undoall.c	2013-02-19 23:54:34.000000000 +0200
+++ src/undoall.c	2013-02-19 23:50:31.000000000 +0200
@@ -16,7 +16,9 @@
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #include <config.h>
+#if HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 #include <errno.h>
 #include <error.h>
 #include <fcntl.h>
@@ -31,7 +33,11 @@
 {
   struct prelink_entry *ent = * (struct prelink_entry **) p;
   DSO *dso;
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
   struct prelink_link *hardlink;
   char *move = NULL;
   size_t movelen = 0;
@@ -47,7 +53,11 @@
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
@@ -88,7 +98,11 @@
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
@@ -126,7 +140,7 @@
 	    }
 	}
 
-      memcpy (mempcpy (move, hardlink->canon_filename, len), ".#prelink#",
+      memcpy (memcpy (move, hardlink->canon_filename, len) + len, ".#prelink#",
 	      sizeof (".#prelink#"));
       if (rename (hardlink->canon_filename, move) < 0)
 	{
