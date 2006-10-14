--- polkitd/policy.c.orig	Tue Mar 14 07:14:33 2006
+++ polkitd/policy.c	Tue May  2 01:53:06 2006
@@ -537,13 +537,15 @@
 	int rc;
 	char *res;
 	char *buf = NULL;
-	unsigned int bufsize;
+	long bufsize;
 	struct passwd pwd;
 	struct passwd *pwdp;
 
 	res = NULL;
 
 	bufsize = sysconf (_SC_GETPW_R_SIZE_MAX);
+	if (bufsize < 0)
+		bufsize = 1024;
 	buf = g_new0 (char, bufsize);
 
 	rc = getpwuid_r (uid, &pwd, buf, bufsize, &pwdp);
@@ -567,13 +569,15 @@
 	int rc;
 	char *res;
 	char *buf = NULL;
-	unsigned int bufsize;
+	long bufsize;
 	struct group gbuf;
 	struct group *gbufp;
 
 	res = NULL;
 
 	bufsize = sysconf (_SC_GETGR_R_SIZE_MAX);
+	if (bufsize < 0)
+		bufsize = 1024;
 	buf = g_new0 (char, bufsize);
 		
 	rc = getgrgid_r (gid, &gbuf, buf, bufsize, &gbufp);
@@ -597,13 +601,15 @@
 	int rc;
 	uid_t res;
 	char *buf = NULL;
-	unsigned int bufsize;
+	long bufsize;
 	struct passwd pwd;
 	struct passwd *pwdp;
 
 	res = (uid_t) -1;
 
 	bufsize = sysconf (_SC_GETPW_R_SIZE_MAX);
+	if (bufsize < 0)
+		bufsize = 1024;
 	buf = g_new0 (char, bufsize);
 		
 	rc = getpwnam_r (username, &pwd, buf, bufsize, &pwdp);
@@ -627,13 +633,15 @@
 	int rc;
 	gid_t res;
 	char *buf = NULL;
-	unsigned int bufsize;
+	long bufsize;
 	struct group gbuf;
 	struct group *gbufp;
 
 	res = (gid_t) -1;
 
 	bufsize = sysconf (_SC_GETGR_R_SIZE_MAX);
+	if (bufsize < 0)
+		bufsize = 1024;
 	buf = g_new0 (char, bufsize);
 		
 	rc = getgrnam_r (groupname, &gbuf, buf, bufsize, &gbufp);
@@ -649,6 +657,23 @@
 	return res;
 }
 
+static int
+getgrouplist_ala_linux (const char *name,
+			gid_t basegid,
+			gid_t *groups,
+			int *ngroups)
+{
+	if (groups)
+		return getgrouplist (name, basegid, groups, ngroups);
+	else {
+		for (*ngroups = 1;; (*ngroups)++) {
+			gid_t _groups[*ngroups];
+			if (getgrouplist (name, basegid, _groups, ngroups) != -1)
+				return 0;
+		}
+	}
+}
+
 PolicyResult 
 policy_get_allowed_resources_for_policy_for_uid (uid_t                  uid, 
 						 const char            *policy, 
@@ -665,9 +690,9 @@
 	if ((username = policy_util_uid_to_name (uid, &default_gid)) == NULL)
 		goto out;
 
-	if (getgrouplist(username, default_gid, NULL, &num_groups) < 0) {
+	if (getgrouplist_ala_linux(username, default_gid, NULL, &num_groups) < 0) {
 		groups = (gid_t *) g_new0 (gid_t, num_groups);
-		if (getgrouplist(username, default_gid, groups, &num_groups) < 0) {
+		if (getgrouplist_ala_linux(username, default_gid, groups, &num_groups) < 0) {
 			g_warning ("getgrouplist() failed");
 			goto out;
 		}
@@ -702,9 +727,9 @@
 	if ((username = policy_util_uid_to_name (uid, &default_gid)) == NULL)
 		goto out;
 
-	if (getgrouplist(username, default_gid, NULL, &num_groups) < 0) {
+	if (getgrouplist_ala_linux(username, default_gid, NULL, &num_groups) < 0) {
 		groups = (gid_t *) g_new0 (gid_t, num_groups);
-		if (getgrouplist(username, default_gid, groups, &num_groups) < 0) {
+		if (getgrouplist_ala_linux(username, default_gid, groups, &num_groups) < 0) {
 			g_warning ("getgrouplist() failed");
 			goto out;
 		}
