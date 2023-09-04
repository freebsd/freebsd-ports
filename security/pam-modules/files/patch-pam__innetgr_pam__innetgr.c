--- pam_innetgr/pam_innetgr.c.orig	2022-02-04 15:04:47 UTC
+++ pam_innetgr/pam_innetgr.c
@@ -121,6 +121,14 @@ stripdomain(char *hostname, char const *domainname)
 	return -1;
 }
 
+#if HAVE_GETDOMAINNAME
+static int
+getdomainname_size_t(char *name, size_t namelen)
+{
+	return getdomainname(name, (int)namelen);
+}
+#endif
+
 int
 get_host_domain_names(char **host_name_ptr, char **domain_name_ptr)
 {
@@ -131,7 +139,7 @@ get_host_domain_names(char **host_name_ptr, char **dom
 		return -1;
 #if HAVE_GETDOMAINNAME
 	if (use_getdomainname) {
-		if (xgetname(getdomainname, &domainname)) {
+		if (xgetname(getdomainname_size_t, &domainname)) {
 			_pam_log(LOG_ERR, "getdomainname: %s", strerror(errno));
 		} else if (strcmp (domainname, "(none)") == 0) {
 			free(domainname);
