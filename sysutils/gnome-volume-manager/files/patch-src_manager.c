--- src/manager.c.orig	Mon Jul 31 16:37:36 2006
+++ src/manager.c	Wed Dec 20 14:59:45 2006
@@ -23,9 +23,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <dirent.h>
+#include <fcntl.h>
 #include <signal.h>
 #include <unistd.h>
 #include <utmp.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 
 #include <locale.h>
 
@@ -3088,10 +3091,17 @@ gvm_local_user (void)
 	struct utmp *utmp;
 	const char *user;
 	size_t ulen;
+#ifndef __linux__
+	int bytes, fd;
+	struct stat sb;
+	struct utmp buf[1024];
+	long len;
+#endif
 	
 	user = g_get_user_name ();
 	ulen = strlen (user);
 	
+#ifdef __linux__
 	setutent ();
 	
 	while (!local && (utmp = getutent ())) {
@@ -3103,7 +3113,31 @@ gvm_local_user (void)
 	}
 	
 	endutent ();
-	
+#else
+	if ((fd = open (_PATH_WTMP, O_RDONLY, 0)) < 0 || fstat(fd, &sb) == -1) {
+		close (fd);
+		return TRUE;
+	}
+	len = (sb.st_size + sizeof(buf) - 1) / sizeof(buf);
+
+	while (!local && --len >= 0) {
+		if (lseek(fd, (off_t) (len * sizeof(buf)), L_SET) == -1 ||
+			(bytes = read (fd, buf, sizeof(buf))) == -1) {
+			close (fd);
+			return TRUE;
+		}
+		for (utmp = &buf[bytes / sizeof(buf[0]) - 1]; !local && utmp >= buf; --utmp) {
+			if (!utmp->ut_name[0] || strncmp (utmp->ut_name, user, ulen) != 0)
+				continue;
+			local = utmp->ut_line[0] == ':' && utmp->ut_line[1] >= '0' && utmp->ut_line[1] <= '9';
+			if (!local)
+				/* Handle vty logins */
+				local = strlen(utmp->ut_line) > 4 && strncmp(utmp->ut_line, "ttyv", 4) == 0 && utmp->ut_line[4] >= '0' && utmp->ut_line[4] <= '9';
+		}
+	}
+
+	close (fd);
+#endif
 	return local;
 }
 
