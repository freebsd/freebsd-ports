diff -Nur src/canonicalize.c src/canonicalize.c
--- src/canonicalize.c	2013-02-19 23:54:34.000000000 +0200
+++ src/canonicalize.c	2013-02-19 23:50:31.000000000 +0200
@@ -73,7 +73,11 @@
    The result is malloc'd.  */
 
 static char *
+#if __LINUX__
 canon_filename (const char *name, int nested, struct stat64 *stp)
+#else
+canon_filename (const char *name, int nested, struct stat *stp)
+#endif
 {
   char *rpath, *dest, *extra_buf = NULL;
   const char *start, *end, *rpath_limit;
@@ -145,7 +149,11 @@
 	      if (ep != NULL)
 		{
 		  char *dirname = (char *) (ep + 1);
+#if __LINUX__
 		  struct stat64 st;
+#else
+		  struct stat st;
+#endif
 
 		  ep->dirname = (const char *) dirname;
 		  ep->dirname_len = e.dirname_len;
@@ -182,7 +190,7 @@
 		  rpath = new_rpath;
 		  rpath_limit = rpath + new_size;
 		}
-	      dest = mempcpy (rpath, ep->canon_dirname, ep->canon_dirname_len);
+	      dest = memcpy (rpath, ep->canon_dirname, ep->canon_dirname_len) + ep->canon_dirname_len;
 	      *dest = '\0';
 	      name = end + 1;
 	    }
@@ -238,10 +246,14 @@
 	      dest = rpath + dest_offset;
 	    }
 
-	  dest = mempcpy (dest, start, end - start);
+	  dest = memcpy (dest, start, end - start) + (end-start);
 	  *dest = '\0';
 
+#if __LINUX__
 	  if (lstat64 (rpath, stp) < 0)
+#else
+	  if (lstat (rpath, stp) < 0)
+#endif
 	    goto error;
 
 	  stp_initialized = 1;
@@ -294,7 +306,11 @@
     --dest;
   *dest = '\0';
 
+#if __LINUX__
   if (!stp_initialized && lstat64 (rpath, stp) < 0)
+#else
+  if (!stp_initialized && lstat (rpath, stp) < 0)
+#endif
     goto error;
 
   if (dest + 1 - rpath <= (rpath_limit - rpath) / 2)
@@ -312,8 +328,16 @@
 }
 
 char *
+#if __LINUX__
 prelink_canonicalize (const char *name, struct stat64 *stp)
+#else
+prelink_canonicalize (const char *name, struct stat *stp)
+#endif
 {
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
   return canon_filename (name, 0, stp ? stp : &st);
 }
