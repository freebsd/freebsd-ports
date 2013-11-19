--- ./libpkg/fetch.c.orig	2013-07-06 05:48:19.000000000 -0500
+++ ./libpkg/fetch.c	2013-11-19 11:13:45.352130038 -0600
@@ -179,6 +179,8 @@
 	return (EPKG_FATAL);
 }
 
+#define URL_SCHEME_PREFIX	"pkg+"
+
 int
 pkg_fetch_file_to_fd(struct pkg_repo *repo, const char *url, int dest, time_t *t)
 {
@@ -204,6 +206,7 @@
 	int kq = -1, flags = 0;
 	struct kevent e, ev;
 	struct timespec ts;
+	bool pkg_url_scheme = false;
 
 	if (pkg_config_int64(PKG_CONFIG_FETCH_RETRY, &max_retry) == EPKG_FATAL)
 		max_retry = 3;
@@ -215,6 +218,34 @@
 
 	retry = max_retry;
 
+	/* A URL of the form http://host.example.com/ where
+	 * host.example.com does not resolve as a simple A record is
+	 * not valid according to RFC 2616 Section 3.2.2.  Our usage
+	 * with SRV records is incorrect.  However it is encoded into
+	 * /usr/sbin/pkg in various releases so we can't just drop it.
+         *
+         * Instead, introduce new pkg+http://, pkg+https://,
+	 * pkg+ssh://, pkg+ftp://, pkg+file:// to support the
+	 * SRV-style server discovery, and also to allow eg. Firefox
+	 * to run pkg-related stuff given a pkg+foo:// URL.
+	 *
+	 * Warn if using plain http://, https:// etc with SRV
+	 */
+
+	if (strncmp(URL_SCHEME_PREFIX, url, strlen(URL_SCHEME_PREFIX)) == 0) {
+		if (repo->mirror_type != SRV) {
+			pkg_emit_error("packagesite URL error for %s -- "
+				       URL_SCHEME_PREFIX
+				       ":// implies SRV mirror type", url);
+
+			/* Too early for there to be anything to cleanup */
+			return(EPKG_FATAL);
+		}
+
+		url += strlen(URL_SCHEME_PREFIX);
+		pkg_url_scheme = true;
+	}
+
 	u = fetchParseURL(url);
 	if (t != NULL)
 		u->ims_time = *t;
@@ -253,6 +284,12 @@
 			if (repo != NULL && repo->mirror_type == SRV &&
 			    (strncmp(u->scheme, "http", 4) == 0
 			     || strcmp(u->scheme, "ftp") == 0)) {
+
+				if (!pkg_url_scheme)
+					pkg_emit_notice(
+     "Warning: use of %s:// URL scheme with SRV records is deprecated: "
+     "switch to pkg+%s://", u->scheme, u->scheme);
+
 				snprintf(zone, sizeof(zone),
 				    "_%s._tcp.%s", u->scheme, u->host);
 				if (repo->srv == NULL)
@@ -268,8 +305,10 @@
 			}
 		}
 
-		if (repo != NULL && repo->mirror_type == SRV && repo->srv != NULL)
+		if (repo != NULL && repo->mirror_type == SRV && repo->srv != NULL) {
 			strlcpy(u->host, srv_current->host, sizeof(u->host));
+			u->port = srv_current->port;
+		}
 		else if (repo != NULL && repo->mirror_type == HTTP && repo->http != NULL) {
 			strlcpy(u->scheme, http_current->url->scheme, sizeof(u->scheme));
 			strlcpy(u->host, http_current->url->host, sizeof(u->host));
@@ -366,7 +405,7 @@
 
 	cleanup:
 
-	if (strcmp(u->scheme, "ssh") != 0) {
+	if (u != NULL && strcmp(u->scheme, "ssh") != 0) {
 		if (remote != NULL)
 			fclose(remote);
 	} else {
