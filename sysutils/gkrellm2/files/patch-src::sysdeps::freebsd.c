Index: src/sysdeps/freebsd.c
diff -u -p src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	2010-01-05 08:12:21.000000000 +0900
+++ src/sysdeps/freebsd.c	2010-01-19 20:13:55.380695497 +0900
@@ -255,7 +255,11 @@ pcpu_probe_done:
 
 #include <limits.h>
 #include <paths.h>
+#if __FreeBSD_version < 900007
 #include <utmp.h>
+#else
+#include <utmpx.h>
+#endif
 
 static int	oid_v_forks[CTL_MAXNAME + 2];
 static int	oid_v_vforks[CTL_MAXNAME + 2];
@@ -364,12 +368,20 @@ gkrellm_sys_proc_read_users(void)
 	gint		n_users;
 	struct stat	sb, s;
 	gchar		ttybuf[MAXPATHLEN];
+#ifdef _PATH_UTMP
 	FILE		*ut;
 	struct utmp	utmp;
+#define UTMP_FILE	_PATH_UTMP
+#else
+	struct utmpx	*utmp;
+#define UTMP_FILE	"/var/run/utx.active"
+#endif
 	static time_t	utmp_mtime;
 
-	if (stat(_PATH_UTMP, &s) != 0 || s.st_mtime == utmp_mtime)
+	if (stat(UTMP_FILE, &s) != 0 || s.st_mtime == utmp_mtime)
 		return;
+
+#ifdef _PATH_UTMP
 	if ((ut = fopen(_PATH_UTMP, "r")) != NULL)
 		{
 		n_users = 0;
@@ -379,14 +391,30 @@ gkrellm_sys_proc_read_users(void)
 				continue;
 			(void)snprintf(ttybuf, sizeof(ttybuf), "%s/%s",
 				       _PATH_DEV, utmp.ut_line);
-			/* corrupted record */
 			if (stat(ttybuf, &sb))
-				continue;
+				continue;	/* corrupted record */
 			++n_users;
 			}
 		(void)fclose(ut);
 		gkrellm_proc_assign_users(n_users);
 		}
+#else
+	setutxent();
+	n_users = 0;
+	while ((utmp = getutxent()) != NULL)
+		{
+		if (utmp->ut_type != USER_PROCESS)
+			continue;
+		(void)snprintf(ttybuf, sizeof(ttybuf), "%s/%s",
+			       _PATH_DEV, utmp->ut_line);
+		if (stat(ttybuf, &sb))
+			continue;		/* corrupted record */
+		++n_users;
+		}
+	endutxent();
+	gkrellm_proc_assign_users(n_users);
+#endif
+
 	utmp_mtime = s.st_mtime;
 	}
 
