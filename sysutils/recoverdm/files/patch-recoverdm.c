--- recoverdm.c.orig	Fri Dec  2 13:34:00 2005
+++ recoverdm.c	Mon Jan 23 16:51:28 2006
@@ -179,7 +179,7 @@
 
 		if (rc == 0)
 		{
-			if (create_sector(sector_list, n_raw_retries, block_size, &dummy) == -1)
+			if (create_sector((unsigned char **)sector_list, n_raw_retries, block_size, &dummy) == -1)
 				rc = -1;
 		}
 
@@ -261,7 +261,7 @@
 		case 'V':
 			return 0;
 		case 'b':
-			start_offset = atoll(optarg);
+			start_offset = strtoll(optarg, (char **)NULL, 10);
 			break;
 		case '?':
 		case 'h':
@@ -295,7 +295,7 @@
 	buffer = (char *)mymalloc(block_size, "sectorbuffer");
 	buffer2 = (char *)mymalloc(block_size, "sectorbuffer for retries");
 
-	fdout = open64(file_out, O_WRONLY | O_CREAT | O_EXCL | O_SYNC, S_IRUSR | S_IWUSR);
+	fdout = open64(file_out, O_WRONLY | O_CREAT | O_EXCL | O_FSYNC, S_IRUSR | S_IWUSR);
 	if (fdout == -1)
 	{
 		printf("Cannot create file %s! (%s)\n", file_out, strerror(errno));
@@ -430,7 +430,7 @@
 				/* always mark the sector as tricky */
 				if (dsecfile)
 				{
-					fprintf(dsecfile, "%lld %ld\n", curpos, block_size);
+					fprintf(dsecfile, "%lld %ld\n", curpos, (long)block_size);
 					fflush(dsecfile);
 				}
 
