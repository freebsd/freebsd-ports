--- import/clone.c.orig	Thu Mar 27 19:17:57 2003
+++ import/clone.c	Thu Mar 27 19:19:16 2003
@@ -74,6 +74,8 @@
     perror("open file");
     return(-1);
   }
+  fcntl(sfd, F_SETFD, FD_CLOEXEC);
+
   
   if(verbose & TC_DEBUG) fprintf(stderr, "(%s) reading video frame sync data from %s\n", __FILE__, logfile);
   
@@ -349,7 +351,8 @@
 	if(verbose & TC_SYNC) fprintf(stderr, "READ (%d)\n", i);
 
 	if((j=p_read(sfd, (char *) ptr->sync_info, sizeof(sync_info_t))) != sizeof(sync_info_t)) {
-	    
+	   
+		if(j < 0) perror("p_read failed");
 	    if(verbose & TC_DEBUG) fprintf(stderr, "(%s) p_read error (%d/%d)\n",  __FILE__, j, sizeof(sync_info_t));
 	    pthread_mutex_lock(&buffer_fill_lock);
 	    clone_read_thread_flag=0;
