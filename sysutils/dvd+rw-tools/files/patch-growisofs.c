--- growisofs.c_old	2006-01-26 22:16:54.000000000 +0100
+++ growisofs.c	2006-02-15 00:00:44.000000000 +0100
@@ -355,12 +355,17 @@
  * - Treat only x73xx OPC errors as fatal;
  * - Fix typo in -speed scaling code;
  * - permit tracksize to be not divisible by 32KB in DAO mode;
+ * 6.1.1: (by Nicolas Boichat, Bacula project)
+ * - Allow session to cross 4GB boundary regardless of medium type
+ *   (don't need to have a DL media)
+ * - Add a -F option (used instead of -M or -Z), which displays next_session
+ *   offset and capacity (free space = next_session - capacity).
  */
 #define PRINT_VERSION(cmd)	do {			\
     char *s=strrchr((cmd),'/');				\
     s ? s++ : (s=(cmd));				\
     printf ("* %.*sgrowisofs by <appro@fy.chalmers.se>,"\
-	    " version 6.1,\n",(int)(s-(cmd)),(cmd));	\
+	    " version 6.1.1,\n",(int)(s-(cmd)),(cmd));	\
 } while (0)
 
 #define _LARGEFILE_SOURCE 
@@ -2329,6 +2334,18 @@
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
@@ -2542,7 +2559,9 @@
 		fprintf (stderr,"    you most likely want to use -Z option.\n"), 
 		exit (FATAL_START(errno));
 
-	    if (dev_found == 'M')
+		if ((dev_found == 'M') || 
+			((dev_found == 'F') && !(mmc_profile&0x10000)) && (saved_descriptors[0].type[0] || saved_descriptors[0].type[1] || saved_descriptors[0].type[2]))
+				/* -F : The medium is not blank, there is a fs on it (the_buffer[0,1 or 2] != 0), so compute next_session. */
 	    {	if (memcmp (saved_descriptors[0].type,"\1CD001",6))
 	            fprintf (stderr,":-( %s doesn't look like isofs...\n",
 		    		in_device), exit(FATAL_START(EMEDIUMTYPE));
@@ -2565,7 +2584,7 @@
 			exit(FATAL_START(EINVAL));
 		}
 		else if (next_session > (0x200000-0x5000)) /* 4GB/2K-40MB/2K */
-		    if ((mmc_profile&0xFFFF)!=0x2B || !no_4gb_check)
+		    if (!no_4gb_check)
 			fprintf (stderr,":-( next session would cross 4GB "
 					"boundary, aborting...\n"),
 			exit (FATAL_START(ENOSPC));
@@ -2608,7 +2627,7 @@
 	exit (FATAL_START(EINVAL));
 
     if (imgfd<0)
-    {	if (mkisofs_argc==1)
+    {	if ((mkisofs_argc==1) && (dev_found != 'F'))
 	    fprintf (stderr,"%s: no mkisofs options specified, "
 			    "aborting...\n",argv[0]),
 	    exit (FATAL_START(EINVAL));
@@ -2880,6 +2899,15 @@
 	}
     }
 
+	if (dev_found == 'F') {
+		off64_t capacity = 0;
+		printf("next_session=%lld\n", next_session*CD_BLOCK);
+		if (ioctl_handle!=INVALID_HANDLE)
+			capacity = get_capacity (ioctl_handle);
+		printf("capacity=%lld\n", capacity);
+		exit(0);
+	}
+
     if (imgfd>=0)
     {	quiet--;
 	if (builtin_dd (imgfd,out_fd,next_session*CD_BLOCK) < 0)
