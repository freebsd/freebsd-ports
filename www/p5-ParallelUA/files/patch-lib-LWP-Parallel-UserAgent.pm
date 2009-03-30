--- lib/LWP/Parallel/UserAgent.pm.orig	2009-03-04 10:33:02.000000000 +0800
+++ lib/LWP/Parallel/UserAgent.pm	2009-03-04 10:33:08.000000000 +0800
@@ -1494,7 +1494,6 @@
     $cookie_jar->add_cookie_header($request) if $cookie_jar;
 
     # Transfer some attributes to the protocol object
-    $protocol->parse_head($parse_head);
     $protocol->max_size($max_size);
 
     LWP::Debug::trace ("<- (undef".
