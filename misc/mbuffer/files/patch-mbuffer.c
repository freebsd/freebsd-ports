--- mbuffer.c.orig	2008-12-08 09:20:47.000000000 +0800
+++ mbuffer.c	2008-12-27 03:21:03.000000000 +0800
@@ -32,7 +32,6 @@
 #include <fcntl.h>
 #include <libgen.h>
 #include <limits.h>
-#include <malloc.h>
 #include <math.h>
 #include <pthread.h>
 #include <semaphore.h>
@@ -45,13 +44,21 @@
 #include <sys/mman.h>
 #include <sys/stat.h>
 #include <sys/time.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #include <termios.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 
 #ifdef HAVE_SENDFILE
 #ifdef HAVE_SENDFILE_H
 #include <sys/sendfile.h>
 #endif
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/uio.h>
 /* if this sendfile implementation does not support sending from buffers,
    disable sendfile support */
 	#ifndef SFV_FD_SELF
@@ -855,7 +862,7 @@
 			err = fsync(fd);
 		while ((err != 0) && (errno == EINTR));
 		if (err != 0) {
-			if ((errno == EINVAL) || (errno == EBADRQC)) {
+			if ((errno == EINVAL)) {
 				infomsg("syncing unsupported on %s: omitted.\n",d->arg);
 			} else {
 				warningmsg("unable to sync %s: %s\n",d->arg,strerror(errno));
@@ -1126,7 +1133,7 @@
 		err = fsync(d->fd);
 	while ((err != 0) && (errno == EINTR));
 	if (err != 0) {
-		if ((errno == EINVAL) || (errno == EBADRQC)) {
+		if ((errno == EINVAL)) {
 			infomsg("syncing unsupported on %s: omitted.\n",d->arg);
 		} else {
 			warningmsg("unable to sync %s: %s\n",d->arg,strerror(errno));
@@ -1608,12 +1615,22 @@
 	const char *outfile = 0;
 	struct sigaction sig;
 	dest_t *dest = 0;
-#if defined(_SC_AVPHYS_PAGES) && defined(_SC_PAGESIZE) && !defined(__CYGWIN__)
-	long pgsz, nump;
+#if (defined(_SC_AVPHYS_PAGES) && defined(_SC_PAGESIZE) && !defined(__CYGWIN__)) || defined(__FreeBSD__)
+#if defined(__FreeBSD__)
+	unsigned long nump;
+	size_t nump_size = sizeof(nump_size);
+#else
+	long nump;
+#endif
+	long pgsz;
 
 	pgsz = sysconf(_SC_PAGESIZE);
 	assert(pgsz > 0);
+#if defined(__FreeBSD__)
+	sysctlbyname("hw.availpages", &nump, &nump_size, NULL, 0);
+#else
 	nump = sysconf(_SC_AVPHYS_PAGES);
+#endif
 	assert(nump > 0);
 	Blocksize = pgsz;
 	Numblocks = nump/50;
@@ -1664,6 +1681,8 @@
 			debugmsg("Verbose = %d\n",Verbose);
 #if defined(_SC_AVPHYS_PAGES) && defined(_SC_PAGESIZE) && !defined(__CYGWIN__)
 			debugmsg("total # of phys pages: %li (pagesize %li)\n",nump,pgsz);
+#elif defined(__FreeBSD__)
+			debugmsg("total # of phys pages: %li (pagesize %li)\n",nump,pgsz);
 #endif
 			debugmsg("default buffer set to %d blocks of %lld bytes\n",Numblocks,Blocksize);
 		} else if (!argcheck("-u",argv,&c,argc)) {
@@ -1760,7 +1779,7 @@
 			Status = 0;
 		} else if (!strcmp("-c",argv[c])) {
 			debugmsg("enabling full synchronous I/O\n");
-			OptSync = O_DSYNC;
+			OptSync = O_FSYNC;
 		} else if (!argcheck("-a",argv,&c,argc)) {
 			Autoloader = 1;
 			Autoload_time = atoi(argv[c]);
@@ -1864,7 +1883,14 @@
 	/* SPW END */
 
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
 	} else if (Numblocks > (unsigned long long) mxnrsem) {
@@ -1874,8 +1900,12 @@
 	if ((Blocksize * (long long)Numblocks) > (long long)SSIZE_MAX)
 		fatal("Cannot address so much memory (%lld*%d=%lld>%lld).\n",Blocksize,Numblocks,Blocksize*(long long)Numblocks,(long long)SSIZE_MAX);
 	/* create buffer */
-	Buffer = (char **) memalign(sysconf(_SC_PAGESIZE),Numblocks * sizeof(char *));
-	if (!Buffer)
+#if defined(__FreeBSD__) && (__FreeBSD_version < 700000)
+	Buffer = (char **) valloc(Numblocks * sizeof(char *));
+#else
+	err = posix_memalign(&Buffer,sysconf(_SC_PAGESIZE),Numblocks * sizeof(char *));
+#endif
+	if (err || !Buffer)
 		fatal("Could not allocate enough memory (%d requested): %s\n",Numblocks * sizeof(char *),strerror(errno));
 	if (Memmap) {
 		infomsg("mapping temporary file to memory with %llu blocks with %llu byte (%llu kB total)...\n",(unsigned long long) Numblocks,(unsigned long long) Blocksize,(unsigned long long) ((Numblocks*Blocksize) >> 10));
