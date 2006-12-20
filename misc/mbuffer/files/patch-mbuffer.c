--- mbuffer.c.orig	Fri Jul 28 23:05:14 2006
+++ mbuffer.c	Mon Dec 18 13:22:57 2006
@@ -16,15 +16,18 @@
 #include <stdlib.h>
 #include <strings.h>
 #include <string.h>
-#include <stropts.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
 #include <sys/time.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #include <termios.h>
 #include <unistd.h>
 
 #ifdef HAVE_SENDFILE
-#include <sys/sendfile.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/uio.h>
 /* if this sendfile implementation does not support sending from buffers,
    disable sendfile support */
 	#ifndef SFV_FD_SELF
@@ -1033,11 +1036,13 @@
 			totalmem = calcint(argv,c,totalmem);
 			optMset = 1;
 			if (totalmem < 100) {
-				long pgsz, nump;
+				long pgsz;
+				unsigned long nump;
+				size_t nump_size = sizeof(nump_size);
 				pgsz = sysconf(_SC_PAGESIZE);
 				assert(pgsz > 0);
-				nump = sysconf(_SC_PHYS_PAGES);
-				assert(pgsz > 0);
+				sysctlbyname("hw.availptotals", &nump, &nump_size, NULL, 0);
+				assert(nump > 0);
 				debugmsg("total # of phys pages: %li (pagesize %li)\n",nump,pgsz);
 				totalmem = ((unsigned long long) nump * pgsz * totalmem) / 100 ;
 			}
@@ -1046,8 +1051,8 @@
 			Numblocks = (atoi(argv[c])) ? ((unsigned long long) atoll(argv[c])) : Numblocks;
 			optBset = 1;
 			debugmsg("Numblocks = %llu\n",Numblocks);
-#ifdef HAVE_STRUCT_STAT_ST_BLKSIZE
 		} else if (!argcheck("-d",argv,&c)) {
+#ifdef HAVE_STRUCT_STAT_ST_BLKSIZE
 			setOutsize = 1;
 			debugmsg("setting output size according to the blocksize of the device\n");
 #else
@@ -1112,7 +1117,7 @@
 			Status = 0;
 		} else if (!strcmp("-c",argv[c])) {
 			debugmsg("enabling full synchronous I/O\n");
-			OptSync = O_DSYNC;
+			OptSync = O_FSYNC;
 		} else if (!argcheck("-a",argv,&c)) {
 			Autoloader = 1;
 			Autoload_time = atoi(argv[c]);
@@ -1202,7 +1207,14 @@
 		fatal("multi volume support for input needs an explicit given input device (option -i)\n");
 
 	/* check that we stay within system limits */
-	mxnrsem = sysconf(_SC_SEM_VALUE_MAX);
+	{
+		int semvmx;
+		size_t semvmx_size = sizeof(semvmx);
+		if (sysctlbyname("kern.ipc.semvmx", &semvmx, &semvmx_size, NULL, 0) == -1)
+			mxnrsem = -1;
+		else
+			mxnrsem = semvmx;
+	}
 	if (-1 == mxnrsem) {
 		warningmsg("unable to determine maximum value of semaphores\n");
 	} else if (Numblocks > (unsigned long long) mxnrsem)
