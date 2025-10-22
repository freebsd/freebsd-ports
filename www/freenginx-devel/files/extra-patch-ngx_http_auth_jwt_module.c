--- ../ngx-http-auth-jwt-module-2.3.1/src/ngx_http_auth_jwt_module.c.orig	2025-02-04 20:24:57.122767000 -0500
+++ ../ngx-http-auth-jwt-module-2.3.1/src/ngx_http_auth_jwt_module.c	2025-02-04 20:25:14.922658000 -0500
@@ -866,17 +866,10 @@
     jwt_location.data += strlen(COOKIE_PREFIX);
     jwt_location.len -= strlen(COOKIE_PREFIX);
 
-#ifndef NGX_LINKED_LIST_COOKIES
-    if (ngx_http_parse_multi_header_lines(&r->headers_in.cookies, &jwt_location, &jwtCookieVal) != NGX_DECLINED)
-    {
-      has_cookie = true;
-    }
-#else
     if (ngx_http_parse_multi_header_lines(r, r->headers_in.cookie, &jwt_location, &jwtCookieVal) != NULL)
     {
       has_cookie = true;
     }
-#endif
 
     if (has_cookie == true)
     {
