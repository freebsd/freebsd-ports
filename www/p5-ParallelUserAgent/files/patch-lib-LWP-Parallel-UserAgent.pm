--- lib/LWP/Parallel/UserAgent.pm.orig	2016-05-29 14:13:43 UTC
+++ lib/LWP/Parallel/UserAgent.pm
@@ -1517,7 +1517,6 @@ sub init_request {
 
     # Transfer some attributes to the protocol object
     $protocol->can('parse_head') ?
-   $protocol->parse_head($parse_head) :
    $protocol->_elem('parse_head', $parse_head);
     $protocol->max_size($max_size);
 
