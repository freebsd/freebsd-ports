--- t/010_core/request-as_string.t.orig	2012-04-21 19:35:27.611579798 +0900
+++ t/010_core/request-as_string.t	2012-04-21 19:35:44.449321956 +0900
@@ -4,6 +4,9 @@
 use HTTP::Engine;
 use t::Utils;
 
+delete $ENV{HTTP_PROXY};
+delete $ENV{HTTP_TIMEOUT};
+
 test_req( gen_request() );
 
 sub gen_request {
