--- apache2/mod_proxy_uwsgi.c.orig	2015-12-30 09:08:49 UTC
+++ apache2/mod_proxy_uwsgi.c
@@ -259,7 +259,7 @@ static request_rec *ap_proxy_make_fake_r
     return rp;
 }
 
-static apr_status_t ap_proxy_buckets_lifetime_transform(request_rec *r,
+apr_status_t ap_proxy_buckets_lifetime_transform(request_rec *r,
         apr_bucket_brigade *from, apr_bucket_brigade *to)
 {
     apr_bucket *e;
