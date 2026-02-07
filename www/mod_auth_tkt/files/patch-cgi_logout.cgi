diff --git a/cgi/logout.cgi b/cgi/logout.cgi
index b2a830c..41fa7e1 100755
--- a/cgi/logout.cgi
+++ b/cgi/logout.cgi
@@ -33,16 +33,19 @@ $back ||= $q->cookie($at->back_cookie_name) if $at->back_cookie_name;
 $back ||= $q->param($at->back_arg_name) if $at->back_arg_name;
 $back = $AuthTktConfig::DEFAULT_BACK_LOCATION if $AuthTktConfig::DEFAULT_BACK_LOCATION;
 $back ||= $ENV{HTTP_REFERER} if $ENV{HTTP_REFERER} && $AuthTktConfig::BACK_REFERER;
-if ($back && $back =~ m!^/!) {
-  my $hostname = $server_name;
-  my $port = $server_port;
-  $hostname .= ':' . $port if $port && $port != 80 && $port != 443;
-  $back = sprintf "http%s://%s%s", ($port == 443 ? 's' : ''), $hostname, $back;
-} elsif ($back && $back !~ m/^http/i) {
-  $back = 'http://' . $back;
+my $back_html = '';
+if ($back) {
+  if ($back =~ m!^/!) {
+    my $hostname = $server_name;
+    my $port = $server_port;
+    $hostname .= ':' . $port if $port && $port != 80 && $port != 443;
+    $back = sprintf "http%s://%s%s", ($port == 443 ? 's' : ''), $hostname, $back;
+  } elsif ($back !~ m/^http/i) {
+    $back = 'http://' . $back;
+  }
+  $back = uri_unescape($back) if $back =~ m/^https?%3A%2F%2F/;
+  $back_html = escapeHTML($back);
 }
-$back = uri_unescape($back) if $back =~ m/^https?%3A%2F%2F/;
-my $back_html = escapeHTML($back) if $back;
 
 # Logout by resetting the auth cookie
 my @cookies = cookie(-name => $at->cookie_name, -value => '', -expires => '-1h', 
