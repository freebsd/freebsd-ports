--- misc/e2fuzz.c.orig	2020-03-23 08:29:36 UTC
+++ misc/e2fuzz.c
@@ -278,8 +278,8 @@ static int process_fs(const char *fsname)
 			c |= 0x80;
 		if (verbose)
 			printf("Corrupting byte %lld in block %lld to 0x%x\n",
-			       off % fs->blocksize,
-			       off / fs->blocksize, c);
+			       (long long)off % fs->blocksize,
+			       (long long)off / fs->blocksize, c);
 		if (dryrun)
 			continue;
 #ifdef HAVE_PWRITE64
