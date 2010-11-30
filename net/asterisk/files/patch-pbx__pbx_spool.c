--- ./pbx/pbx_spool.c.orig	2010-10-18 17:32:40.000000000 +0200
+++ ./pbx/pbx_spool.c	2010-11-30 11:14:19.000000000 +0100
@@ -26,11 +26,6 @@
 
 ASTERISK_FILE_VERSION(__FILE__, "$Revision: 292083 $")
 
-/* Handling of call files using inotify is not functioning correctly currently:
- * Issue 18089 - https://issues.asterisk.org/view.php?id=18089 
- */
-#undef HAVE_INOTIFY
-
 #include <sys/stat.h>
 #include <time.h>
 #include <utime.h>
@@ -67,7 +62,7 @@
 	 */
 	SPOOL_FLAG_ALWAYS_DELETE = (1 << 0),
 	/* Don't unlink the call file after processing, move in qdonedir */
-	SPOOL_FLAG_ARCHIVE = (1 << 1)
+	SPOOL_FLAG_ARCHIVE = (1 << 1),
 };
 
 static char qdir[255];
@@ -260,24 +255,18 @@
 
 static void safe_append(struct outgoing *o, time_t now, char *s)
 {
-	int fd;
 	FILE *f;
-	struct utimbuf tbuf;
-
-	if ((fd = open(o->fn, O_WRONLY | O_APPEND)) < 0)
-		return;
+	struct utimbuf tbuf = { .actime = now, .modtime = now + o->retrytime };
 
-	if ((f = fdopen(fd, "a"))) {
+	if ((f = fopen(o->fn, "a"))) {
 		fprintf(f, "\n%s: %ld %d (%ld)\n", s, (long)ast_mainpid, o->retries, (long) now);
 		fclose(f);
-	} else
-		close(fd);
+	}
 
 	/* Update the file time */
-	tbuf.actime = now;
-	tbuf.modtime = now + o->retrytime;
-	if (utime(o->fn, &tbuf))
+	if (utime(o->fn, &tbuf)) {
 		ast_log(LOG_WARNING, "Unable to set utime on %s: %s\n", o->fn, strerror(errno));
+	}
 }
 
 /*!
@@ -288,7 +277,6 @@
  */
 static int remove_from_queue(struct outgoing *o, const char *status)
 {
-	int fd;
 	FILE *f;
 	char newfn[256];
 	const char *bname;
@@ -297,8 +285,9 @@
 		struct stat current_file_status;
 
 		if (!stat(o->fn, &current_file_status)) {
-			if (time(NULL) < current_file_status.st_mtime)
+			if (time(NULL) < current_file_status.st_mtime) {
 				return 0;
+			}
 		}
 	}
 
@@ -313,26 +302,28 @@
 		return -1;
 	}
 
-	if ((fd = open(o->fn, O_WRONLY | O_APPEND))) {
-		if ((f = fdopen(fd, "a"))) {
-			fprintf(f, "Status: %s\n", status);
-			fclose(f);
-		} else
-			close(fd);
+	if (!(bname = strrchr(o->fn, '/'))) {
+		bname = o->fn;
+	} else {
+		bname++;
 	}
 
-	if (!(bname = strrchr(o->fn, '/')))
-		bname = o->fn;
-	else
-		bname++;	
 	snprintf(newfn, sizeof(newfn), "%s/%s", qdonedir, bname);
 	/* a existing call file the archive dir is overwritten */
 	unlink(newfn);
 	if (rename(o->fn, newfn) != 0) {
 		unlink(o->fn);
 		return -1;
-	} else
-		return 0;
+	}
+
+	/* Only append to the file AFTER we move it out of the watched directory,
+	 * otherwise the fclose() causes another event for inotify(7) */
+	if ((f = fopen(newfn, "a"))) {
+		fprintf(f, "Status: %s\n", status);
+		fclose(f);
+	}
+
+	return 0;
 }
 
 static void *attempt_thread(void *data)
@@ -399,7 +390,7 @@
 	}
 
 	/* Attempt to open the file */
-	if (!(f = fopen(fn, "r+"))) {
+	if (!(f = fopen(fn, "r"))) {
 		remove_from_queue(o, "Failed");
 		free_outgoing(o);
 		ast_log(LOG_WARNING, "Unable to open %s: %s, deleting\n", fn, strerror(errno));
@@ -414,7 +405,7 @@
 		fclose(f);
 		return -1;
 	}
-	
+
 #if 0
 	printf("Filename: %s, Retries: %d, max: %d\n", fn, o->retries, o->maxretries);
 #endif
@@ -432,7 +423,7 @@
 			   so abort their retry and continue as we were... */
 			if (o->callingpid)
 				safe_append(o, time(NULL), "AbortRetry");
-			
+
 			safe_append(o, now, "StartRetry");
 			launch_service(o);
 		}
@@ -455,6 +446,7 @@
 
 /* Only one thread is accessing this list, so no lock is necessary */
 static AST_LIST_HEAD_NOLOCK_STATIC(dirlist, direntry);
+static AST_LIST_HEAD_NOLOCK_STATIC(createlist, direntry);
 
 static void queue_file(const char *filename, time_t when)
 {
@@ -482,14 +474,12 @@
 		when = st.st_mtime;
 	}
 
-#ifndef HAVE_INOTIFY
-	/* Need to check the existing list for kqueue(2), in order to avoid duplicates. */
+	/* Need to check the existing list in order to avoid duplicates. */
 	AST_LIST_TRAVERSE(&dirlist, cur, list) {
 		if (cur->mtime == when && !strcmp(filename, cur->name)) {
 			return;
 		}
 	}
-#endif
 
 	if ((res = when) > now || (res = scan_service(filename, now)) > 0) {
 		if (!(new = ast_calloc(1, sizeof(*new) + strlen(filename) + 1))) {
@@ -517,6 +507,40 @@
 	}
 }
 
+#ifdef HAVE_INOTIFY
+static void queue_file_create(const char *filename)
+{
+	struct direntry *cur;
+
+	AST_LIST_TRAVERSE(&createlist, cur, list) {
+		if (!strcmp(cur->name, filename)) {
+			return;
+		}
+	}
+
+	if (!(cur = ast_calloc(1, sizeof(*cur) + strlen(filename) + 1))) {
+		return;
+	}
+	strcpy(cur->name, filename);
+	AST_LIST_INSERT_TAIL(&createlist, cur, list);
+}
+
+static void queue_file_write(const char *filename)
+{
+	struct direntry *cur;
+	/* Only queue entries where an IN_CREATE preceded the IN_CLOSE_WRITE */
+	AST_LIST_TRAVERSE_SAFE_BEGIN(&createlist, cur, list) {
+		if (!strcmp(cur->name, filename)) {
+			AST_LIST_REMOVE_CURRENT(list);
+			ast_free(cur);
+			queue_file(filename, 0);
+			break;
+		}
+	}
+	AST_LIST_TRAVERSE_SAFE_END
+}
+#endif
+
 static void *scan_thread(void *unused)
 {
 	DIR *dir;
@@ -557,7 +581,7 @@
 	}
 
 #ifdef HAVE_INOTIFY
-	inotify_add_watch(inotify_fd, qdir, IN_CLOSE_WRITE | IN_MOVED_TO);
+	inotify_add_watch(inotify_fd, qdir, IN_CREATE | IN_CLOSE_WRITE | IN_MOVED_TO);
 #endif
 
 	/* First, run through the directory and clear existing entries */
@@ -567,7 +591,7 @@
 	}
 
 #ifndef HAVE_INOTIFY
-	EV_SET(&kev, dirfd(dir), EVFILT_VNODE, EV_ADD | EV_ENABLE, NOTE_WRITE | NOTE_EXTEND | NOTE_DELETE | NOTE_REVOKE | NOTE_ATTRIB, 0, NULL);
+	EV_SET(&kev, dirfd(dir), EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR, NOTE_WRITE, 0, NULL);
 	if (kevent(inotify_fd, &kev, 1, NULL, 0, &nowait) < 0 && errno != 0) {
 		ast_log(LOG_ERROR, "Unable to watch directory %s: %s\n", qdir, strerror(errno));
 	}
@@ -598,7 +622,15 @@
 				(res = read(inotify_fd, &buf, sizeof(buf))) >= sizeof(buf.iev)) {
 				/* File(s) added to directory, add them to my list */
 				do {
-					queue_file(buf.iev.name, 0);
+					if (buf.iev.mask & IN_CREATE) {
+						queue_file_create(buf.iev.name);
+					} else if (buf.iev.mask & IN_CLOSE_WRITE) {
+						queue_file_write(buf.iev.name);
+					} else if (buf.iev.mask & IN_MOVED_TO) {
+						queue_file(buf.iev.name, 0);
+					} else {
+						ast_log(LOG_ERROR, "Unexpected event %d for file '%s'\n", (int) buf.iev.mask, buf.iev.name);
+					}
 					res -= sizeof(buf.iev) + buf.iev.len;
 					if (res >= sizeof(buf.iev)) {
 						memmove(&buf.iev, &buf.iev.name[buf.iev.len], res);
