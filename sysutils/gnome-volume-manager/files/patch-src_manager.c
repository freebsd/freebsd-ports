--- src/manager.c.orig	Tue Nov  7 13:01:17 2006
+++ src/manager.c	Sun Dec 31 15:33:44 2006
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
 
@@ -1556,12 +1559,27 @@ enum {
 	MOUNT_UID        = (1 << 15),
 	MOUNT_UMASK      = (1 << 16),
 	MOUNT_UTF8       = (1 << 17),
+	MOUNT_LOCALE     = (1 << 18),
+	MOUNT_LONGNAME   = (1 << 19),
 };
 
 static struct {
 	const char *name;
 	guint32 flag;
 } mount_options[] = {
+#ifdef __FreeBSD__
+	{ "-D=",	MOUNT_CODEPAGE   },  /* vfat */
+	{ "-M=",	MOUNT_DMASK      },  /* vfat */
+	{ "-m=",	MOUNT_FMASK      },  /* vfat, ntfs */
+	{ "-L=",	MOUNT_LOCALE     },  /* vfat */
+	{ "-C=",	MOUNT_IOCHARSET  },  /* ntfs, ios9660 */
+	{ "noatime",	MOUNT_NOATIME    },
+	{ "noexec",	MOUNT_NOEXEC     },
+	{ "ro",		MOUNT_READ_ONLY  },
+	{ "longnames",	MOUNT_LONGNAME   },  /* vfat */
+	{ "sync",	MOUNT_SYNC       },
+	{ "-u=",	MOUNT_UID        },  /* vfat, ntfs */
+#else
 	{ "codepage=",  MOUNT_CODEPAGE   },  /* vfat */
 	{ "data=",      MOUNT_DATA       },  /* ext3 */
 	{ "dirsync",    MOUNT_DIRSYNC    },
@@ -1580,6 +1598,7 @@ static struct {
 	{ "uid=",       MOUNT_UID        },  /* vfat, ntfs, udf, iso9660 */
 	{ "umask=",     MOUNT_UMASK      },  /* vfat, ntfs, udf */
 	{ "utf8",       MOUNT_UTF8       },  /* vfat, iso9660 */
+#endif
 };
 
 
@@ -1760,10 +1779,17 @@ gvm_mount_options (GPtrArray *options, g
 		g_slist_free_1 (l);
 	}
 	
+#ifndef __FreeBSD__
 	if (opts & MOUNT_UID) {
 		option = g_strdup_printf ("uid=%u", getuid ());
 		g_ptr_array_add (options, option);
 	}
+#else
+	if (opts & MOUNT_UID && (!strcmp (where, "vfat") || !strcmp (where, "ntfs"))) {
+		option = g_strdup_printf ("u=%u", getuid ());
+		g_ptr_array_add (options, option);
+	}
+#endif
 	
 	return TRUE;
 }
@@ -1813,7 +1839,7 @@ gvm_device_mount (const char *udi, gbool
 		
 		return retval;
 	} else {
-		char *mount_point, *fstype, *drive, **moptions, fmask_opt[12], *charset_opt = NULL;
+		char *mount_point, *fstype, *drive, **moptions, fmask_opt[12], *charset_opt = NULL, *locale_opt = NULL;
 		DBusMessage *dmesg, *reply;
 		gboolean freev = FALSE;
 		GPtrArray *options;
@@ -1893,21 +1919,86 @@ gvm_device_mount (const char *udi, gbool
 				
 				if (opts & MOUNT_FMASK) {
 					mask = umask (0);
+#ifdef __FreeBSD__
+					snprintf (fmask_opt, sizeof (fmask_opt), "-m=%#o", mask | 0111);
+#else
 					snprintf (fmask_opt, sizeof (fmask_opt), "fmask=%#o", mask | 0111);
+#endif
 					g_ptr_array_add (options, fmask_opt);
 					umask (mask);
 				}
 				
 				if (opts & MOUNT_SHORTNAME)
 					g_ptr_array_add (options, "shortname=lower");
+				if (opts & MOUNT_LONGNAME)
+					g_ptr_array_add (options, "longnames");
+
+				if (opts & MOUNT_LOCALE) {
+					char *locale;
+
+					locale = setlocale(LC_ALL, NULL);
+					if (!locale)
+						locale = getenv("LANG");
+					if (locale) {
+
+						locale_opt = g_strdup_printf ("-L=%s", locale);
+						g_ptr_array_add (options, locale_opt);
+					}
+				}
+
+#ifdef __FreeBSD__
+				if (opts & MOUNT_CODEPAGE) {
+					if ((iocharset = gvm_iocharset ())) {
+						charset_opt = g_strdup_printf ("-D=%s", iocharset);
+						g_ptr_array_add (options, charset_opt);
+					}
+				}
+
+				if (opts & MOUNT_UID) {
+					snprintf (uid, sizeof (uid) - 1, "-u=%s", getuid ());
+					g_ptr_array_add (options, uid);
+				}
+#endif
 			} else if (!strcmp (fstype, "iso9660")) {
 				/* only care about uid= and iocharset= */
+#ifdef __FreeBSD__
+				if (opts & MOUNT_IOCHARSET) {
+					if ((iocharset = gvm_iocharset ())) {
+						charset_opt = g_strdup_printf ("-C=%s", iocharset);
+						g_ptr_array_add (options, charset_opt);
+					}
+				}
+#endif
 			} else if (!strcmp (fstype, "udf")) {
 				/* also care about uid= and iocharset= */
 				if (opts & MOUNT_NOATIME)
 					g_ptr_array_add (options, "noatime");
+#ifdef __FreeBSD__
+				if (opts & MOUNT_IOCHARSET) {
+					if ((iocharset = gvm_iocharset ())) {
+						charset_opt = g_strdup_printf ("-C=%s", iocharset);
+						g_ptr_array_add (options, charset_opt);
+					}
+				}
+#endif
+			} else if (!strcmp (fstype, "ntfs")) {
+				/* only care about uid= and iocharset= */
+#ifdef __FreeBSD__
+				if (opts & MOUNT_IOCHARSET) {
+					if ((iocharset = gvm_iocharset ())) {
+						charset_opt = g_strdup_printf ("-C=%s", iocharset);
+						g_ptr_array_add (options, charset_opt);
+					}
+				}
+
+				if (opts & MOUNT_UID) {
+					snprintf (uid, sizeof (uid) - 1, "-u=%s", getuid ());
+					g_ptr_array_add (options, uid);
+				}
+#endif
 			}
 			
+#ifndef __FreeBSD__
 			if (opts & (MOUNT_IOCHARSET|MOUNT_UTF8)) {
 				if ((iocharset = gvm_iocharset ())) {
 					if ((opts & MOUNT_UTF8) && !strcmp (iocharset, "utf8")) {
@@ -1923,6 +2014,7 @@ gvm_device_mount (const char *udi, gbool
 				snprintf (uid, sizeof (uid) - 1, "uid=%u", getuid ());
 				g_ptr_array_add (options, uid);
 			}
+#endif
 			
 			libhal_free_string (fstype);
 		}
@@ -1947,6 +2039,7 @@ gvm_device_mount (const char *udi, gbool
 		
 		g_ptr_array_free (options, TRUE);
 		g_free (charset_opt);
+		g_free (locale_opt);
 		
 		policy = g_new (struct _MountPolicy, 1);
 		policy->udi = g_strdup (udi);
@@ -3185,6 +3278,12 @@ gvm_local_user (void)
 	size_t n;
 	DIR *dir;
 	int vt;
+#ifndef __linux__
+	int bytes, fd;
+	struct stat sb;
+	struct utmp buf[1024];
+	size_t len;
+#endif
 	
 	if (local & LOCAL_USER_CHECKED)
 		return (local & LOCAL_USER_FOUND);
@@ -3208,6 +3307,7 @@ gvm_local_user (void)
 	
  fallback:
 	
+#ifdef __linux__
 	if (!(local & LOCAL_USER_FOUND)) {
 		setutent ();
 		
@@ -3222,6 +3322,29 @@ gvm_local_user (void)
 		
 		endutent ();
 	}
+#else
+	if ((fd = open (_PATH_WTMP, O_RDONLY, 0)) < 0 || fstat(fd, &sb) == -1) {
+		close (fd);
+		return TRUE;
+	}
+
+	len = (sb.st_size + sizeof(buf) - 1) / sizeof(buf);
+
+	while (!local && --len >= 0) {
+		if (lseek(fd, (off_t) (len * sizeof(buf)), L_SET) == -1 ||
+				(bytes = read (fd, buf, sizeof(buf))) == -1) {
+			close (fd);
+			return TRUE;
+		}
+		for (utmp = &buf[bytes / sizeof(buf[0]) - 1]; !local && utmp >= buf; --utmp) {
+			if (!utmp->ut_name[0] || strncmp (utmp->ut_name, user, n) != 0)
+				continue;
+			local = utmp->ut_line[0] == ':' && utmp->ut_line[1] >= '0' && utmp->ut_line[1] <= '9' || !strncmp (utmp->ut_line, "ttyv", 4) ? LOCAL_USER_FOUND : 0;
+		}
+	}
+
+	close (fd);
+#endif
 	
 	local |= LOCAL_USER_CHECKED;
 	
