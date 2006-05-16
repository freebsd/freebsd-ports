--- lib/Net/Google/Calendar.pm.orig	Wed Apr 26 22:23:27 2006
+++ lib/Net/Google/Calendar.pm	Wed May 17 06:52:56 2006
@@ -176,7 +176,7 @@
         $url .= "gsessionid=".$self->{_session_id};
     }
 
-    my %params = ( Content_Type => 'application/atom+xml',
+    my %params = ( Content_Type => 'application/atom+xml; charset=UTF-8',
                    Authorization => "GoogleLogin auth=".$self->{_auth},
                    Content => $entry->as_xml );
 
