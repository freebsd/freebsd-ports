--- ./minidlna.c.orig	2013-11-02 05:06:41.000000000 +0400
+++ ./minidlna.c	2013-11-13 17:25:27.000000000 +0400
@@ -365,6 +365,7 @@
 		open_db(&db);
 		if (*scanner_pid == 0) /* child (scanner) process */
 		{
+			DPRINTF(E_DEBUG, L_GENERAL, "Starting scanner in forked child\n");
 			start_scanner();
 			sqlite3_close(db);
 			log_close();
@@ -373,6 +374,7 @@
 		}
 		else if (*scanner_pid < 0)
 		{
+			DPRINTF(E_DEBUG, L_GENERAL, "Starting scanner in parent\n");
 			start_scanner();
 		}
 #else
@@ -997,6 +999,15 @@
 		else if (pthread_create(&inotify_thread, NULL, start_inotify, NULL) != 0)
 			DPRINTF(E_FATAL, L_GENERAL, "ERROR: pthread_create() failed for start_inotify. EXITING\n");
 	}
+#elif defined(HAVE_SYS_EVENT_H)
+	if( GETFLAG(INOTIFY_MASK) )
+	{
+		if (!sqlite3_threadsafe() || sqlite3_libversion_number() < 3005001)
+			DPRINTF(E_ERROR, L_GENERAL, "SQLite library is not threadsafe!	"
+			"Kqueue will be disabled.\n");
+		else if (pthread_create(&inotify_thread, NULL, start_kqueue, NULL) != 0)
+			DPRINTF(E_FATAL, L_GENERAL, "ERROR: pthread_create() failed for start_kqueue. EXITING\n");
+	}
 #endif
 	smonitor = OpenAndConfMonitorSocket();
 
