--- remmina/src/remmina_file.c.orig	2016-10-31 23:54:16 UTC
+++ remmina/src/remmina_file.c
@@ -64,7 +64,7 @@
 #define MIN_WINDOW_WIDTH 10
 #define MIN_WINDOW_HEIGHT 10
 
-static struct timespec times[2];
+static struct timeval times[2];
 
 typedef struct _RemminaSetting
 {
@@ -631,16 +631,21 @@ remmina_file_touch(RemminaFile *remminaf
 	TRACE_CALL("remmina_file_touch");
 	int fd;
 	struct stat st;
+	struct timeval tv_atim, tv_mtim;
 	int r;
 
 	if ((r = stat(remminafile->filename, &st)) < 0) {
 		if (errno != ENOENT)
 			remmina_log_printf("stat %s:", remminafile->filename);
 	} else if (!r) {
-		times[0] = st.st_atim;
-		times[1] = st.st_mtim;
-		if (utimensat(AT_FDCWD, remminafile->filename, times, 0) < 0)
-			remmina_log_printf("utimensat %s:", remminafile->filename);
+		tv_atim.tv_sec = st.st_atim.tv_sec;
+		tv_atim.tv_usec = st.st_atim.tv_nsec / 1000;
+		tv_mtim.tv_sec = st.st_mtim.tv_sec;
+		tv_mtim.tv_usec = st.st_mtim.tv_nsec / 1000;
+		times[0] = tv_atim;
+		times[1] = tv_mtim;
+		if (utimes(remminafile->filename, times) < 0)
+			remmina_log_printf("utimes %s:", remminafile->filename);
 		return;
 	}
 
