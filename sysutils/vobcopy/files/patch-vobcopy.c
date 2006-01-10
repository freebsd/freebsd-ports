--- vobcopy.c.orig	Wed Dec  7 21:31:56 2005
+++ vobcopy.c	Sun Jan  8 10:47:02 2006
@@ -146,6 +146,8 @@
 #endif
   
   
+  /* initialize string */
+  dvd_path[0] = '\0';
 
   /*
    * the getopt part (getting the options from command line)
@@ -1695,8 +1697,12 @@
     fprintf( stderr, "Used statvfs\n" );
 #endif
   temp1 = buf1.f_bavail;
+#ifdef USE_STATFS
+  temp2 = buf1.f_bsize;
+#else
   /* On Solaris at least, f_bsize is not the actual block size -- lb */
   temp2 = buf1.f_frsize;
+#endif
   sum = ( ( off_t )temp1 * ( off_t )temp2 );
   if( verbosity_level >= 1 )
     {
@@ -1733,8 +1739,12 @@
     fprintf( stderr, "Used statvfs\n" );
 #endif
   temp1 = buf2.f_blocks;
+#ifdef USE_STATFS
+  temp2 = buf2.f_bsize;
+#else
   /* On Solaris at least, f_bsize is not the actual block size -- lb */
   temp2 = buf2.f_frsize;
+#endif
   sum = ( ( off_t )temp1 * ( off_t )temp2 );
   if( verbosity_level >= 1 )
     {
