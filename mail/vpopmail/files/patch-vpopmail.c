--- vpopmail.c.orig	Mon Mar  1 16:33:32 2004
+++ vpopmail.c	Sun Apr 18 01:11:37 2004
@@ -2462,6 +2462,11 @@
 
   mytime = time(NULL);
 
+  ipaddr = get_remote_ip();
+  if ( ipaddr == NULL ) {
+      return 0;
+  }
+
 #ifdef FILE_LOCKING
   /* by default the OPEN_SMTP_LOK_FILE is ~vpopmail/etc/open-smtp.lock */
   if ( (fs_lok_file=fopen(OPEN_SMTP_LOK_FILE, "w+")) == NULL) return(-1);
@@ -2481,10 +2486,10 @@
     }
   }
 
-  /* by default the OPEN_SMTP_TMP_FILE is ~vpopmail/etc/open-smtp.tmp */
+  /* by default the OPEN_SMTP_TMP_FILE is ~vpopmail/etc/open-smtp.tmp.pid */
   snprintf(open_smtp_tmp_filename, sizeof(open_smtp_tmp_filename),
            "%s.%lu", OPEN_SMTP_TMP_FILE, (long unsigned)getpid());
-  /* create the tmp file as open-smtp.tmp.pid */
+  /* create the tmp file */
   fs_tmp_file = fopen(open_smtp_tmp_filename, "w+");
 
   if ( fs_tmp_file == NULL ) {
@@ -2493,17 +2498,6 @@
     fclose(fs_lok_file);
 #endif /* FILE_LOCKING */
     /* failed to create the tmp file */
-    return(-1);
-  }
-
-  ipaddr = get_remote_ip();
-
-  if ( ipaddr == NULL ) {     
-#ifdef FILE_LOCKING
-    unlock_lock(fileno(fs_lok_file), 0, SEEK_SET, 0);
-    fclose(fs_lok_file);
-#endif /* FILE_LOCKING */
-    /* failed to get user's ip address */
     return(-1);
   }
 
