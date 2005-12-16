--- buffer.c.orig	Sat Jan 19 20:47:17 2002
+++ buffer.c	Tue Dec 13 11:57:38 2005
@@ -114,12 +114,17 @@
 #include <signal.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <machine/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <sys/sem.h>
 #include <sys/wait.h>
+#include <sys/time.h>
+#include <limits.h>
+#include <stdlib.h>
+#include <strings.h>
 #include "sem.h"
 
 #ifndef lint
@@ -127,7 +132,6 @@
 #endif
 
 #ifndef __alpha
-extern char *shmat();
 #endif /* __alpha */
 
 /* General macros */
@@ -252,6 +256,8 @@
 /* Number of K output */
 unsigned long outk = 0;
 
+struct timeval starttime;
+
 int
 main( argc, argv )
 	int argc;
@@ -263,6 +269,8 @@
 
 	buffer_allocate();
 
+	gettimeofday(&starttime, NULL);
+
 	start_reader_and_writer();
 
 	byee( 0 );
@@ -384,8 +392,8 @@
 			fprintf( stderr, "Usage: %s [-B] [-t] [-S size] [-m memsize] [-b blocks] [-p percent] [-s blocksize] [-u pause] [-i infile] [-o outfile] [-z size]\n",
 				progname );
 			fprintf( stderr, "-B = blocked device - pad out last block\n" );
-			fprintf( stderr, "-t = show total amount writen at end\n" );
-			fprintf( stderr, "-S size = show amount writen every size bytes\n" );
+			fprintf( stderr, "-t = show total amount written at end\n" );
+			fprintf( stderr, "-S size = show amount written every size bytes\n" );
 			fprintf( stderr, "-m size = size of shared mem chunk to grab\n" );
 			fprintf( stderr, "-b num = number of blocks in queue\n" );
 			fprintf( stderr, "-p percent = don't start writing until percent blocks filled\n" );
@@ -398,6 +406,11 @@
 		}
 	}
 
+	if (argc > optind) {
+		fprintf( stderr, "too many arguments\n" );
+		byee( -1 );
+	}
+
 	if (zflag) showevery = blocksize;
 
 	/* If -b was not given try and work out the max buffer size */
@@ -507,9 +520,9 @@
 	get_buffer();
 
 	if( debug )
-		fprintf( stderr, "%s pbuffer is 0x%08x, buffer_size is %d [%d x %d]\n",
+		fprintf( stderr, "%s pbuffer is 0x%08lx, buffer_size is %d [%d x %d]\n",
 			proc_string,
-			(char *)pbuffer, buffer_size, blocks, blocksize );
+			(unsigned long)pbuffer, buffer_size, blocks, blocksize );
 
 #ifdef SYS5
 	memset( (char *)pbuffer, '\0', buffer_size );
@@ -526,9 +539,11 @@
 	lock( pbuffer->semid, pbuffer->blocks_used_lock );
 
 	pbuffer->blocks_free_lock = 1;
-	/* start this off so lock() can be called on it for each block
-	 * till all the blocks are used up */
-	sem_set( pbuffer->semid, pbuffer->blocks_free_lock, blocks - 1 );
+	/* Initializing the semaphore to "blocks - 1" causes a hang when using option
+	 * "-p 100" because it always keeps one block free, so we'll never reach 100% fill
+	 * level. However, there doesn't seem to be a good reason to keep one block free,
+	 * so we initialize the semaphore to "blocks" instead. */
+	sem_set( pbuffer->semid, pbuffer->blocks_free_lock, blocks );
 
 	/* Detattach the shared memory so the fork doesnt do anything odd */
 	shmdt( (char *)pbuffer );
@@ -648,7 +663,7 @@
 int
 fill_block()
 {
-	int bytes;
+	int bytes = 0;
 	char *start;
 	int toread;
 	static char eof_reached = 0;
@@ -707,7 +722,7 @@
 {
 	int filled = 0;
 	int maxfilled = (blocks * percent) / 100;
-	int first_block;
+	int first_block = 0;
 
 	if( debug )
 		fprintf( stderr, "\tW: Entering writer\n blocks = %d\n maxfilled = %d\n",
@@ -914,13 +929,12 @@
 do_size( arg )
 	char *arg;
 {
-	char format[ 20 ];
-	int ret;
+	int ret = 0;
 
-	*format = '\0';
-	sscanf( arg, "%d%s", &ret, format );
+	char unit = '\0';
+	sscanf( arg, "%d%c", &ret, &unit  );
 
-	switch( *format ){
+	switch( unit ){
 	case 'm':
 	case 'M':
 		ret = ret K K;
@@ -941,7 +955,36 @@
 void
 pr_out()
 {
-	fprintf( stderr, " %10luK\r", outk );
+	struct timeval now;
+	unsigned long ms_delta, k_per_s;
+
+	gettimeofday(&now, NULL);
+	ms_delta = (now.tv_sec - starttime.tv_sec) * 1000
+		+ (now.tv_usec - starttime.tv_usec) / 1000;
+	if (ms_delta) {
+		/* Use increased accuracy for small amounts of data,
+		 * decreased accuracy for *huge* throughputs > 4.1GB/s
+		 * to avoid division by 0. This will overflow if your
+		 * machine's throughput exceeds 4TB/s - you deserve to
+		 * loose if you're still using 32 bit longs on such a
+		 * beast ;-)
+		 * <mbuck@debian.org>
+		 */
+		if (outk < ULONG_MAX / 1000) {
+			k_per_s = (outk * 1000) / ms_delta;
+		} else if (ms_delta >= 1000) {
+			k_per_s = outk / (ms_delta / 1000);
+		} else {
+			k_per_s = (outk / ms_delta) * 1000;
+		}
+		fprintf( stderr, " %10luK, %10luK/s\r", outk, k_per_s );
+	} else {
+		if (outk) {
+			fprintf( stderr, " %10luK,          ?K/s\r", outk );
+		} else {
+			fprintf( stderr, "          0K,          0K/s\r");
+		}
+	}
 }
 
 #ifdef SYS5
