--- pam_mkhomedir.c.orig	2010-02-02 13:28:18 UTC
+++ pam_mkhomedir.c
@@ -68,6 +68,89 @@
 #include <security/pam_modules.h>
 #include <security/pam_mod_misc.h>
 
+
+/*
+ * This code is from bin/mkdir/mkdir.c
+ *
+ * Returns 1 if a directory has been created,
+ * 2 if it already existed, and 0 on failure.
+ */
+static int
+build(const char *dir, mode_t omode)
+{
+	struct stat sb;
+	mode_t numask, oumask;
+	int first, last, retval;
+	char path[MAXPATHLEN];
+	char *p;
+
+	if (snprintf(path, sizeof(path), "%s", dir) >= (int)sizeof(path))
+		PAM_LOG("warning: pathname too long '%s'", dir);
+
+	p = path;
+	oumask = 0;
+	retval = 1;
+	if (p[0] == '/')		/* Skip leading '/'. */
+		++p;
+	for (first = 1, last = 0; !last ; ++p) {
+		if (p[0] == '\0')
+			last = 1;
+		else if (p[0] != '/')
+			continue;
+		*p = '\0';
+		if (!last && p[1] == '\0')
+			last = 1;
+		if (first) {
+			/*
+			 * POSIX 1003.2:
+			 * For each dir operand that does not name an existing
+			 * directory, effects equivalent to those caused by the
+			 * following command shall occcur:
+			 *
+			 * mkdir -p -m $(umask -S),u+wx $(dirname dir) &&
+			 *    mkdir [-m mode] dir
+			 *
+			 * We change the user's umask and then restore it,
+			 * instead of doing chmod's.
+			 */
+			oumask = umask(0);
+			numask = oumask & ~(S_IWUSR | S_IXUSR);
+			(void)umask(numask);
+			first = 0;
+		}
+		if (last)
+			(void)umask(oumask);
+		if (mkdir(path, last ? omode : S_IRWXU | S_IRWXG | S_IRWXO) < 0) {
+			if (errno == EEXIST || errno == EISDIR) {
+				if (stat(path, &sb) < 0) {
+					warn("%s", path);
+					retval = 0;
+					break;
+				} else if (!S_ISDIR(sb.st_mode)) {
+					if (last)
+						errno = EEXIST;
+					else
+						errno = ENOTDIR;
+					warn("%s", path);
+					retval = 0;
+					break;
+				}
+				if (last)
+					retval = 2;
+			} else {
+				warn("%s", path);
+				retval = 0;
+				break;
+			}
+		}
+		if (!last)
+		    *p = '/';
+	}
+	if (!first && !last)
+		(void)umask(oumask);
+	return (retval);
+}
+
 void
 copymkdir(char const * dir, char const * skel, mode_t mode, uid_t uid, gid_t gid)
 {
@@ -75,7 +158,7 @@ copymkdir(char const * dir, char const *
 	char            src[MAXPATHLEN];
 	char            dst[MAXPATHLEN];
 
-	if (mkdir(dir, mode) != 0 && errno != EEXIST) {
+	if (build(dir, mode) != 0 && errno != EEXIST) {
 		PAM_LOG("mkdir(%s)", dir);
 	} else {
 		int             infd, outfd;
@@ -211,9 +294,11 @@ pam_sm_open_session(pam_handle_t *pamh,
 		goto err;
 	}
 
-	copymkdir(pwd->pw_dir, skeldir, getmode(set, S_IRWXU | S_IRWXG | S_IRWXO), pwd->pw_uid,pwd->pw_gid);
-	free(set);
-	return (PAM_SUCCESS);
+	if (strcmp(pwd->pw_dir,"/nonexistent") != 0 ) {
+		copymkdir(pwd->pw_dir, skeldir, getmode(set, S_IRWXU | S_IRWXG | S_IRWXO), pwd->pw_uid,pwd->pw_gid);
+		free(set);
+		return (PAM_SUCCESS);
+	}
 
 err:
 	if (openpam_get_option(pamh, "no_fail"))
