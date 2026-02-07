--- lib/AmphetaDesk/WWW.pm.orig	Tue Oct 29 03:30:40 2002
+++ lib/AmphetaDesk/WWW.pm	Mon Oct 10 14:16:59 2005
@@ -103,7 +103,9 @@
       $req->proxy_authorization_basic($un, $pw); }
 
    # set our referer and grab our URL.
+   if (get_setting("user_http_referer")) {
    $req->referer( get_setting("user_http_referer") );
+   }
    my $res = $ua->request($req);
 
    # did things go happily or sadly?
@@ -171,7 +173,9 @@
       $req->proxy_authorization_basic($un, $pw); }
 
    # set our referer and grab our URL.
+   if (get_setting("user_http_referer")) {
    $req->referer( get_setting("user_http_referer") );
+   }
    my $res = $ua->request($req);
 
    # did things go happily or sadly?
