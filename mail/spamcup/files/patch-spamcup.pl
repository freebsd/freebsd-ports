--- spamcup.pl.orig	Wed Jan 26 22:00:19 2005
+++ spamcup.pl	Sun Mar 25 23:51:49 2007
@@ -222,7 +222,7 @@
 
     if ($opt{d}) { # debug
         if ($SCpass) {
-            print "D: GET http://$SCident:******\@members.spamcop.net/\n";
+            print "D: GET http://$SCident:******\@www.spamcop.net/mcgi?action=loginform;returnurl=%2Ft\n";
         } else {
             print "D: GET http://www.spamcop.net/?code=$SCident\n";
         }
@@ -236,7 +236,7 @@
     sleep $delay;
 
     if ($SCpass) {
-        $req = HTTP::Request->new(GET => 'http://members.spamcop.net/');
+        $req = HTTP::Request->new(GET => 'http://www.spamcop.net/mcgi?action=loginform;returnurl=%2F/');
         $req->authorization_basic($SCident, $SCpass);
     } else {
         $req = HTTP::Request->new(GET => 'http://www.spamcop.net/?code='.$SCident);
