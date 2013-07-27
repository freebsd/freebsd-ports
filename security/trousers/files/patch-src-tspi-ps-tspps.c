--- src/tspi/ps/tspps.c.orig	2012-09-20 02:24:48.000000000 +0900
+++ src/tspi/ps/tspps.c	2013-07-27 04:03:25.000000000 +0900
@@ -29,6 +29,11 @@
 #define LE_16 htole16
 #define LE_32 htole32
 #define LE_64 htole64
+#elif defined(HAVE_SYS_ENDIAN_H)
+#include <sys/endian.h>
+#define LE_16 htole16
+#define LE_32 htole32
+#define LE_64 htole64
 #else
 #define LE_16(x) (x)
 #define LE_32(x) (x)
@@ -43,9 +48,13 @@
 #include "tspps.h"
 #include "tsplog.h"
 
+
 static int user_ps_fd = -1;
 static MUTEX_DECLARE_INIT(user_ps_lock);
 #if (defined (__FreeBSD__) || defined (__OpenBSD__))
+#include <sys/endian.h>
+#define	LE_16 htole16
+#define	LE_32 htole32
 static MUTEX_DECLARE_INIT(user_ps_path);
 #endif
 static struct flock fl;
@@ -60,9 +69,7 @@
 	TSS_RESULT result;
 	char *file_name = NULL, *home_dir = NULL;
 	struct passwd *pwp;
-#if (defined (__linux) || defined (linux) || defined(__GLIBC__))
 	struct passwd pw;
-#endif
 	struct stat stat_buf;
 	char buf[PASSWD_BUFSIZE];
 	uid_t euid;
@@ -72,10 +79,6 @@
 		*file = strdup(file_name);
 		return (*file) ? TSS_SUCCESS : TSPERR(TSS_E_OUTOFMEMORY);
 	}
-#if (defined (__FreeBSD__) || defined (__OpenBSD__))
-	MUTEX_LOCK(user_ps_path);
-#endif
-
 	euid = geteuid();
 
 #if defined (SOLARIS)
@@ -88,32 +91,14 @@
          */
         rc = snprintf(buf, sizeof (buf), "%s/%d", TSS_USER_PS_DIR, euid);
 #else
-	setpwent();
-	while (1) {
-#if (defined (__linux) || defined (linux) || defined(__GLIBC__))
-		rc = getpwent_r(&pw, buf, PASSWD_BUFSIZE, &pwp);
-		if (rc) {
-			LogDebugFn("USER PS: Error getting path to home directory: getpwent_r: %s",
-				   strerror(rc));
-			endpwent();
-			return TSPERR(TSS_E_INTERNAL_ERROR);
-		}
+	rc = getpwuid_r(euid, &pw, buf, PASSWD_BUFSIZE, &pwp);
+	if (rc) {
+		LogDebugFn("USER PS: Error getting path to home directory: "
+			"getpwent_r: %s", strerror(rc));
+		return TSPERR(TSS_E_INTERNAL_ERROR);
+	}
 
-#elif (defined (__FreeBSD__) || defined (__OpenBSD__))
-		if ((pwp = getpwent()) == NULL) {
-			LogDebugFn("USER PS: Error getting path to home directory: getpwent: %s",
-                                   strerror(rc));
-			endpwent();
-			MUTEX_UNLOCK(user_ps_path);
-			return TSPERR(TSS_E_INTERNAL_ERROR);
-		}
-#endif
-		if (euid == pwp->pw_uid) {
-                        home_dir = strdup(pwp->pw_dir);
-                        break;
-                }
-        }
-        endpwent();
+	home_dir = strdup(pwp->pw_dir);
 
 	if (!home_dir)
 		return TSPERR(TSS_E_OUTOFMEMORY);
