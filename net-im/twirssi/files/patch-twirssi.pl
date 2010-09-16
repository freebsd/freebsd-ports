--- twirssi.pl	2010-09-16 13:41:22.000000000 -0300
+++ twirssi.pl	2010-09-16 13:37:44.000000000 -0300
@@ -89,6 +89,10 @@
 
     return unless $username = &valid_username($username);
 
+    if (!utf8::is_utf8($text)) {
+        $text = decode("utf8", $text);
+    }
+
     eval {
         if ( $twits{$username}
             ->new_direct_message( { user => $target, text => $text } ) )
@@ -244,6 +248,10 @@
 
     return if &too_long($data);
 
+    if (!utf8::is_utf8($data)) {
+        $data = decode "utf8", $data;
+    }
+
     my $success = 1;
     my $res;
     eval {
@@ -351,6 +359,10 @@
 
     return if &too_long($data);
 
+    if (!utf8::is_utf8($data)) {
+        $data = decode "utf8", $data;
+    }
+
     my $success = 1;
     eval {
         unless (
