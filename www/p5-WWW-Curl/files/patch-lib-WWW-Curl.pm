Description: Fix a grammatical error.
Author: Peter Pentchev <roam@FreeBSD.org>
Bug: http://rt.cpan.org/Public/Bug/Display.html?id=53063
Last-Update: 2009-12-24

--- lib/WWW/Curl.pm.orig
+++ lib/WWW/Curl.pm
@@ -273,7 +273,7 @@
 
 =item curl_multi_fdset
 
-This method returns three arrayrefs: the read, write and exception fds libcurl knows about.
+This method returns three arrayrefs: the read, write, and exception fds libcurl knows about.
 In the case of no file descriptors in the given set, an empty array is returned.
 
 =back
