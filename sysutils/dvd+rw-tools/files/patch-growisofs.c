--- growisofs.c.orig	Sun Sep 24 17:28:53 2006
+++ growisofs.c	Fri Feb  2 12:08:20 2007
@@ -370,12 +370,17 @@
  *   upon Layer Break command, therefore longer timeout is required;
  * - Linux: deploy BLKFLSBUF to avoid media reloads when possible;
  * - add unit buffer utilization indicator [by request from K3b];
+ * 7.0.1: (by Nicolas Boichat, Bacula project)
+ * - Allow session to cross 4GB boundary regardless of medium type
+ *   (dont need to have a DL media)
+ * - Add a -F option (used instead of -M or -Z), which displays next_session
+ *   offset and capacity (free space = next_session - capacity).
  */
 #define PRINT_VERSION(cmd)	do {			\
     char *s=strrchr((cmd),'/');				\
     s ? s++ : (s=(cmd));				\
     printf ("* %.*sgrowisofs by <appro@fy.chalmers.se>,"\
-	    " version 7.0,\n",(int)(s-(cmd)),(cmd));	\
+	    " version 7.0.1,\n",(int)(s-(cmd)),(cmd));	\
 } while (0)
 
 #define _LARGEFILE_SOURCE 
@@ -2773,6 +2778,18 @@
 		else          in_device = argv[++i];
 		dev_found = 'Z';
 	    }
+	    else if (argv[i][1] == 'F')
+	    {	if (len > 2) in_device = argv[i]+2;
+		else	     in_device = argv[++i];
+		dev_found = 'F';
+		dry_run = 1; /* NEVER write anything with -F */
+	    }
+	    else if (!strncmp(opt,"-free-space",11))
+	    {	if (len > 11) in_device = opt+11;
+		else          in_device = argv[++i];
+		dev_found = 'F';
+		dry_run = 1; /* NEVER write anything with -F */
+	    }
 	    else if (!strcmp(opt,"-poor-man"))
 	    {	if (poor_man<0) poor_man = 1;
 		continue;
@@ -2908,6 +2925,9 @@
 		fflush (stdout);
 #if defined(__unix) || defined(__unix__)
 		setuid(getuid());
+# ifdef __FreeBSD__
+		munlockall();
+#endif
 		execlp (mkisofs_argv[0],mkisofs_argv[0],"-version",NULL);
 #elif defined(_WIN32)
 		if (_spawnl (_P_WAIT,mkisofs_argv[0],
@@ -2989,11 +3009,14 @@
 		if (n==0) set_errno(EIO);	/* end-of-file reached? */
 	    }
 	    if (n!=2048 && dev_found=='M')
+	    {
 		perror (":-( unable to pread64(2) primary volume descriptor"),
 		fprintf (stderr,"    you most likely want to use -Z option.\n"), 
 		exit (FATAL_START(errno));
-
-	    if (dev_found == 'M')
+	    }
+		if ((dev_found == 'M') || 
+			((dev_found == 'F') && !(mmc_profile&0x10000)) && (saved_descriptors[0].type[0] || saved_descriptors[0].type[1] || saved_descriptors[0].type[2]))
+				/* -F : The medium is not blank, there is a fs on it (the_buffer[0,1 or 2] != 0), so compute next_session. */
 	    {	if (memcmp (saved_descriptors[0].type,"\1CD001",6))
 	            fprintf (stderr,":-( %s doesn't look like isofs...\n",
 		    		in_device), exit(FATAL_START(EMEDIUMTYPE));
@@ -3016,8 +3039,7 @@
 			exit(FATAL_START(EINVAL));
 		}
 		else if (next_session > (0x200000-0x5000)) /* 4GB/2K-40MB/2K */
-		    if ((mmc_profile&0xFFFF)<0x20 ||
-			((mmc_profile&0xFFFF)<0x40 && !no_4gb_check))
+		    if (!no_4gb_check)
 			fprintf (stderr,":-( next session would cross 4GB "
 					"boundary, aborting...\n"),
 			exit (FATAL_START(ENOSPC));
@@ -3060,7 +3082,7 @@
 	exit (FATAL_START(EINVAL));
 
     if (imgfd<0)
-    {	if (mkisofs_argc==1)
+    {	if ((mkisofs_argc==1) && (dev_found != 'F'))
 	    fprintf (stderr,"%s: no mkisofs options specified, "
 			    "aborting...\n",argv[0]),
 	    exit (FATAL_START(EINVAL));
@@ -3243,6 +3265,15 @@
 		break;
 	}
     }
+
+	if (dev_found == 'F') {
+		off64_t capacity = 0;
+		printf("next_session=%lld\n", next_session*CD_BLOCK);
+		if (ioctl_handle!=INVALID_HANDLE)
+			capacity = get_capacity (ioctl_handle);
+		printf("capacity=%lld\n", capacity);
+		exit(0);
+	}
 
     if (imgfd>=0)
     {	quiet--;
