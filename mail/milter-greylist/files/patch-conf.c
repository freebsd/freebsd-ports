--- conf.c.orig	Fri Apr  2 17:06:52 2004
+++ conf.c	Mon May 31 16:58:06 2004
@@ -34,7 +34,7 @@
 #ifdef HAVE_SYS_CDEFS_H
 #include <sys/cdefs.h>
 #ifdef __RCSID
-__RCSID("$Id: conf.c,v 1.15 2004/04/02 15:06:52 manu Exp $");
+__RCSID("$Id: conf.c,v 1.15 (sigsev patch) 2004/04/02 15:06:52 manu Exp $");
 #endif
 #endif
 
@@ -83,6 +83,8 @@
 conf_load(void) 	/* exceptlist must be write-locked */
 {
 	FILE *stream;
+	pthread_t tid;
+	pthread_attr_t attr;
 
 	/*
 	 * Reset the configuration to its default 
@@ -100,8 +102,49 @@
 		return;
 	}
 
+	/*
+	 * On some platforms, the thread stack limit is too low and
+	 * conf_parse will get a SIGSEGV because it overflows the
+	 * stack.
+	 *
+	 * In order to fix this, we spawn a new thread just for 
+	 * parsing the config file, and we request a stack big 
+	 * enough to hold the parser data. 2 MB seems okay.
+	 */
+
 	conf_in = stream;
-	conf_parse();
+
+	if (pthread_attr_init(&attr) != 0) {
+		syslog(LOG_ERR, "pthread_attr_init failed: %s", 
+		strerror(errno));
+		exit(EX_OSERR);
+	}
+
+	if (pthread_attr_setstacksize(&attr, 2 * 1024 * 1024) != 0) {
+		syslog(LOG_ERR, "pthread_attr_setstacksize failed: %s",
+		strerror(errno));
+		exit(EX_OSERR);
+	}
+
+	if (pthread_create(&tid, &attr, 
+		(void *(*)(void *))conf_parse, NULL) != 0) {
+		syslog(LOG_ERR, "pthread_create failed: %s", 
+		strerror(errno));
+		exit(EX_OSERR);
+	}
+
+	if (pthread_join(tid, NULL) != 0) {
+		syslog(LOG_ERR, "pthread_join failed: %s",
+		strerror(errno));
+		exit(EX_OSERR);
+	}
+
+	if (pthread_attr_destroy(&attr) != 0) {
+		syslog(LOG_ERR, "pthread_attr_destroy failed: %s",
+		strerror(errno));
+		exit(EX_OSERR);
+	}
+
 	fclose(stream);
 
 	(void)gettimeofday(&conffile_modified, NULL);
