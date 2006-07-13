--- lib/WWW/Curl/Multi.pm.orig	Thu Jul 13 15:02:54 2006
+++ lib/WWW/Curl/Multi.pm	Thu Jul 13 15:03:33 2006
@@ -22,7 +22,7 @@
 
 WWW::Curl::Multi is an extension to WWW::Curl::Easy
 which makes it possible to process multiple easy
-handles parallel.
+handles in parallel.
 
 =head1 METHODS
 
@@ -33,7 +33,7 @@
         This method adds a WWW::Curl::Easy object to the multi stack.
 
     $curlm->perform
-        This method parallel perlforms all WWW::Curl::Easy objects
+        This method performs in parallel all the WWW::Curl::Easy objects
         on the stack.
 	
 	*Warning* - this does not perform exactly the
