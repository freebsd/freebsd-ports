--- mergebad.c.orig	Fri Dec  2 13:34:00 2005
+++ mergebad.c	Mon Jan 23 17:00:14 2006
@@ -193,7 +193,7 @@
 		bbs[n_bb].block_size = block_size;
 
 		if (verbose >= 4)
-			printf("%d] %lld %lld\n", n_bb, offset, block_size);
+			printf("%d] %lld %d\n", n_bb, offset, block_size);
 
 		n_bb++;
 	}
@@ -293,7 +293,7 @@
 		}
 		else if (strcmp(argv[loop], "-o") == 0)
 		{
-			fd_out = open64(argv[++loop], O_WRONLY | O_CREAT | O_EXCL | O_SYNC, S_IRUSR | S_IWUSR);
+			fd_out = open64(argv[++loop], O_WRONLY | O_CREAT | O_EXCL | O_FSYNC, S_IRUSR | S_IWUSR);
 			if (fd_out == -1)
 			{
 				fprintf(stderr, "Failed to create file %s: %s (%d)\n", argv[loop], strerror(errno), errno);
@@ -312,10 +312,10 @@
 		}
 		else if (strcmp(argv[loop], "-s") == 0)
 		{
-			length = atoll(argv[++loop]);
+			length = strtoll(argv[++loop], (char **)NULL, 10);
 
 			if (verbose)
-				printf("Length set to: %d\n", length);
+				printf("Length set to: %lld\n", length);
 		}
 		else if (strcmp(argv[loop], "-v") == 0)
 		{
