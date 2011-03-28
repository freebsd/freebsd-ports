--- mbuffer.c.orig	2011-03-18 06:03:24.000000000 +0800
+++ mbuffer.c	2011-03-29 00:20:54.000000000 +0800
@@ -1513,6 +1513,7 @@
 	long mxnrsem;
 	int err, optMset = 0, optSset = 0, optBset = 0, c, fl, numstdout = 0, numthreads = 0, numOut = 0;
 	sigset_t       signalSet;
+	struct sigaction signalIgnoreAct;
 #ifdef HAVE_STRUCT_STAT_ST_BLKSIZE
 	struct stat st;
 #endif
@@ -1525,6 +1526,7 @@
 #if defined(_SC_AVPHYS_PAGES) && defined(_SC_PAGESIZE) && !defined(__CYGWIN__)
 	long pgsz, nump;
 
+	signalIgnoreAct.sa_action = SIG_IGN;
 	TickTime = 1000000 / sysconf(_SC_CLK_TCK);
 	pgsz = sysconf(_SC_PAGESIZE);
 	assert(pgsz > 0);
@@ -2007,7 +2009,7 @@
 	}
 
 	debugmsg("checking if we have a controlling terminal...\n");
-	err = sigignore(SIGTTIN);
+	err = sigaction(SIGTTIN, &signalIgnoreAct, NULL);
 	assert(err == 0);
 	fl = fcntl(STDERR_FILENO,F_GETFL);
 	err = fcntl(STDERR_FILENO,F_SETFL,fl | O_NONBLOCK);
