--- t/010_core/request-as_http_request.t.orig	2012-04-21 18:30:16.644155273 +0900
+++ t/010_core/request-as_http_request.t	2012-04-21 18:30:36.825851307 +0900
@@ -4,6 +4,9 @@
 use HTTP::Engine::Request;
 use t::Utils;
 
+delete $ENV{HTTP_PROXY};
+delete $ENV{HTTP_TIMEOUT};
+
 test_req( gen_request()->as_http_request );
 
 sub gen_request {
