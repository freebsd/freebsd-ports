--- ../nginx-http-auth-digest-bd1c86a/ngx_http_auth_digest_module.c.orig	2011-12-29 04:00:32.000000000 +0400
+++ ../nginx-http-auth-digest-bd1c86a/ngx_http_auth_digest_module.c	2015-06-13 20:18:59.856347000 +0300
@@ -403,11 +403,11 @@
   if (http_method.data==NULL) return NGX_HTTP_INTERNAL_SERVER_ERROR;
   p = ngx_cpymem(http_method.data, r->method_name.data, r->method_end - r->method_name.data+1);
   
-  ha2_key.len = http_method.len + r->uri.len + 1;
+  ha2_key.len = http_method.len + r->unparsed_uri.len + 1;
   ha2_key.data = ngx_pcalloc(r->pool, ha2_key.len);
   if (ha2_key.data==NULL) return NGX_HTTP_INTERNAL_SERVER_ERROR;
   p = ngx_cpymem(ha2_key.data, http_method.data, http_method.len-1); *p++ = ':';
-  p = ngx_cpymem(p, r->uri.data, r->uri.len);
+  p = ngx_cpymem(p, r->unparsed_uri.data, r->unparsed_uri.len);
 
   HA2.len = 33;
   HA2.data = ngx_pcalloc(r->pool, HA2.len);
@@ -487,11 +487,11 @@
     // recalculate the digest with a modified HA2 value (for rspauth) and emit the
     // Authentication-Info header    
     ngx_memset(ha2_key.data, 0, ha2_key.len);
-    p = ngx_sprintf(ha2_key.data, ":%s", r->uri.data);
+    p = ngx_sprintf(ha2_key.data, ":%s", r->unparsed_uri.data);
 
     ngx_memset(HA2.data, 0, HA2.len);
     ngx_md5_init(&md5);
-    ngx_md5_update(&md5, ha2_key.data, r->uri.len);
+    ngx_md5_update(&md5, ha2_key.data, r->unparsed_uri.len);
     ngx_md5_final(hash, &md5);  
     ngx_hex_dump(HA2.data, hash, 16);
 
