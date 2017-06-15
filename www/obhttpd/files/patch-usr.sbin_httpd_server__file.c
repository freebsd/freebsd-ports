OpenBSD 6.0 errata 17, Jan 31, 2017

A bug in the processing of range headers in httpd can lead to memory
exhaustion. This patch disables range header processing.

--- usr.sbin/httpd/server_file.c.orig	2016-10-17 10:49:16 UTC
+++ usr.sbin/httpd/server_file.c
@@ -66,7 +66,6 @@ server_file_access(struct httpd *env, st
 	struct http_descriptor	*desc = clt->clt_descreq;
 	struct server_config	*srv_conf = clt->clt_srv_conf;
 	struct stat		 st;
-	struct kv		*r, key;
 	char			*newpath, *encodedpath;
 	int			 ret;
 
@@ -146,13 +145,7 @@ server_file_access(struct httpd *env, st
 		goto fail;
 	}
 
-	key.kv_key = "Range";
-	r = kv_find(&desc->http_headers, &key);
-	if (r != NULL)
-		return (server_partial_file_request(env, clt, path, &st,
-		    r->kv_value));
-	else
-		return (server_file_request(env, clt, path, &st));
+	return (server_file_request(env, clt, path, &st));
 
  fail:
 	switch (errno) {
