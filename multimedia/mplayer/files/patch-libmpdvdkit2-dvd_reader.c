--- libmpdvdkit2/dvd_reader.c.orig	Sat Aug  9 16:12:35 2003
+++ libmpdvdkit2/dvd_reader.c	Fri Oct  3 18:16:43 2003
@@ -239,6 +239,11 @@
    Darwin  /dev/rdisk0,  it needs to be the raw device
    BSD/OS  /dev/sr0c (if not mounted) or /dev/rsr0c ('c' any letter will do) */
 static char *bsd_block2char( const char *path )
+#if defined(__FreeBSD__)
+{
+    return (char *) strdup( path );
+}
+#else
 {
     char *new_path;
 
@@ -253,6 +258,7 @@
 
     return new_path;
 }
+#endif /* __FreeBSD__ */
 #endif
 
 dvd_reader_t *DVDOpen( const char *path )
