--- recoverdm.c.orig	2009-07-25 22:13:33.105079513 +0900
+++ recoverdm.c	2009-07-25 22:17:04.086068813 +0900
@@ -181,7 +181,7 @@
 
 		if (rc == 0)
 		{
-			if (create_sector(sector_list, n_raw_retries, block_size, &dummy) == -1)
+			if (create_sector((unsigned char **)sector_list, n_raw_retries, block_size, &dummy) == -1)
 				rc = -1;
 		}
 
@@ -267,7 +267,7 @@
 		case 'V':
 			return 0;
 		case 'b':
-			start_offset = atoll(optarg);
+			start_offset = strtoll(optarg, (char **)NULL, 10);
 			break;
 		case '?':
 		case 'h':
@@ -307,7 +307,7 @@
 	buffer = (char *)mymalloc(block_size, "sectorbuffer");
 	buffer2 = (char *)mymalloc(block_size, "sectorbuffer for retries");
 
-	fdout = open64(file_out, O_WRONLY | O_CREAT | O_EXCL | O_SYNC, S_IRUSR | S_IWUSR);
+	fdout = open64(file_out, O_WRONLY | O_CREAT | O_EXCL | O_FSYNC, S_IRUSR | S_IWUSR);
 	if (fdout == -1)
 	{
 		printf("Cannot create file %s! (%s)\n", file_out, strerror(errno));
@@ -442,7 +442,7 @@
 				/* always mark the sector as tricky */
 				if (dsecfile)
 				{
-					fprintf(dsecfile, "%lld %ld\n", curpos, block_size*skip_value);
+					fprintf(dsecfile, "%lld %ld\n", curpos, (long)(block_size*skip_value));
 					fflush(dsecfile);
 				}
 
