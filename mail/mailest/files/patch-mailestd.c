--- mailestd.c.orig	2015-05-27 12:18:27.000000000 +0900
+++ mailestd.c	2015-06-05 16:21:58.350309000 +0900
@@ -809,8 +809,6 @@
 
 	RB_INIT(&folders);
 	ctx = mailestd_get_gather(_this, task->gather_id);
-	mailestd_log(LOG_DEBUG, "Gathering %s ...", mailestd_folder_name(
-	    _this, folder, buf, sizeof(buf)));
 	if (folder[0] == '/')
 		strlcpy(rdir, folder, sizeof(rdir));
 	else {
@@ -818,6 +816,8 @@
 		strlcat(rdir, "/", sizeof(rdir));
 		strlcat(rdir, folder, sizeof(rdir));
 	}
+	mailestd_log(LOG_DEBUG, "Gathering %s ...", mailestd_folder_name(
+	    _this, rdir, buf, sizeof(buf)));
 	paths[0] = rdir;
 	paths[1] = NULL;
 	lrdir = strlen(rdir);
@@ -853,7 +853,7 @@
 	}
 
 	mailestd_log(LOG_DEBUG, "Gathered %s (Total: %d Remove: %d Update: %d)",
-	    mailestd_folder_name(_this, folder, buf, sizeof(buf)),
+	    mailestd_folder_name(_this, rdir, buf, sizeof(buf)),
 	    total, delete, update);
 out:
 	if (ctx != NULL) {
@@ -2638,6 +2638,7 @@
 mailestd_monitor_folder(struct mailestd *_this, const char *dirpath)
 {
 	int		 fd = -1;
+	char		 buf[PATH_MAX];
 	struct folder	*fld, fld0;
 
 	MAILESTD_ASSERT(_thread_self() == _this->monitorworker.thread);
@@ -2659,7 +2660,8 @@
 	fld->fd = fd;
 	fld->path = xstrdup(dirpath);
 	RB_INSERT(folder_tree, &_this->monitors, fld);
-	mailestd_log(LOG_DEBUG, "Start monitoring %s", dirpath);
+	mailestd_log(LOG_DEBUG, "Start monitoring %s",
+	    mailestd_folder_name(_this, dirpath, buf, sizeof(buf)));
 }
 
 static void
