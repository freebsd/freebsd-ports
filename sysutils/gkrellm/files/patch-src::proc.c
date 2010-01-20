Index: src/proc.c
diff -u -p src/proc.c.orig src/proc.c
--- src/proc.c.orig	2002-07-01 11:21:19.000000000 +0900
+++ src/proc.c	2010-01-19 20:51:02.658138473 +0900
@@ -99,7 +99,11 @@ void	(*read_system_proc_info)();
 #include <kvm.h>
 #include <limits.h>
 #include <paths.h>
+#if !defined(__FreeBSD__) || __FreeBSD_version < 900007
 #include <utmp.h>
+#else
+#include <utmpx.h>
+#endif
 
 extern	kvm_t	*kvmd;
 
@@ -153,8 +157,14 @@ read_freebsd_proc()
 	gint		r_forks, r_vforks, r_rforks;
 	gint		len;
 	gint		nextpid, nforked;
+#if !defined(__FreeBSD__) || __FreeBSD_version < 900007
 	FILE		*ut;
 	struct utmp	utmp;
+#define UTMP_FILE	_PATH_UTMP
+#else
+	struct utmpx	*utmp;
+#define UTMP_FILE	"/var/run/utx.active"
+#endif
 	struct stat	sb, s;
 	static time_t	utmp_mtime;
 	gchar		ttybuf[MAXPATHLEN];
@@ -211,8 +221,9 @@ read_freebsd_proc()
 
 	if (!GK.five_second_tick || !proc.extra_info)
 		return;
-	if (stat(_PATH_UTMP, &s) != 0 || s.st_mtime == utmp_mtime)
+	if (stat(UTMP_FILE, &s) != 0 || s.st_mtime == utmp_mtime)
 		return;
+#if !defined(__FreeBSD__) || __FreeBSD_version < 900007
 	if ((ut = fopen(_PATH_UTMP, "r")) != NULL)
 		{
 		proc.n_users = 0;
@@ -222,13 +233,27 @@ read_freebsd_proc()
 				continue;
 			(void)snprintf(ttybuf, sizeof(ttybuf), "%s/%s",
 				       _PATH_DEV, utmp.ut_line);
-			/* corrupted record */
 			if (stat(ttybuf, &sb))
-				continue;
+				continue;	/* corrupted record */
 			++proc.n_users;
 			}
 		(void)fclose(ut);
 		}
+#else
+	setutxent();
+	proc.n_users = 0;
+	while ((utmp = getutxent()) != NULL)
+		{
+		if (utmp->ut_type != USER_PROCESS)
+			continue;
+		(void)snprintf(ttybuf, sizeof(ttybuf), "%s/%s",
+			       _PATH_DEV, utmp->ut_line);
+		if (stat(ttybuf, &sb))
+			continue;		/* corrupted record */
+		++proc.n_users;
+		}
+	endutxent();
+#endif
 	utmp_mtime = s.st_mtime;
 	}
 #endif
