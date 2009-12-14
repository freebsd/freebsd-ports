--- twirssi.pl	2009-11-09 08:40:49.000000000 -0200
+++ twirssi.pl	2009-11-06 18:03:05.000000000 -0200
@@ -851,7 +851,7 @@
     return unless &logged_in($twit);
 
     my ( $fh, $filename ) = File::Temp::tempfile();
-    binmode( $fh, ":utf8" );
+    binmode( $fh, ":" . &get_charset );
     $child_pid = fork();
 
     if ($child_pid) {    # parent
@@ -1213,7 +1213,7 @@
     # pretend
 
     if ( open FILE, $filename ) {
-        binmode FILE, ":utf8";
+        binmode FILE, ":" . &get_charset;
         my @lines;
         my %new_cache;
         while (<FILE>) {
@@ -1596,6 +1596,13 @@
     return 60;
 }
 
+sub get_charset {
+    my $charset = Irssi::settings_get_str("twirssi_charset");
+    print scalar localtime, " - charset: '$charset'" if &debug;
+    return "utf8" if $charset =~ /^\s*$/;
+    return $charset;
+}
+
 sub hilight {
     my $text = shift;
 
@@ -1636,7 +1643,7 @@
                     "Set short_url_args to username,API_key or change your",
                     "short_url_provider."
                 );
-                return decode "utf8", $data;
+                return decode &get_charset, $data;
             }
         }
 
@@ -1653,7 +1660,7 @@
         }
     }
 
-    return decode "utf8", $data;
+    return decode &get_charset, $data;
 }
 
 sub normalize_username {
@@ -1695,6 +1702,7 @@
 );
 
 Irssi::settings_add_int( "twirssi", "twitter_poll_interval", 300 );
+Irssi::settings_add_str( "twirssi", "twirssi_charset",         "utf8" );
 Irssi::settings_add_str( "twirssi", "twitter_window",          "twitter" );
 Irssi::settings_add_str( "twirssi", "bitlbee_server",          "bitlbee" );
 Irssi::settings_add_str( "twirssi", "short_url_provider",      "TinyURL" );
