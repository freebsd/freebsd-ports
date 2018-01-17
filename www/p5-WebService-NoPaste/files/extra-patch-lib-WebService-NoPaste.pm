--- lib/WebService/NoPaste.pm.orig	Tue May  3 20:10:26 2005
+++ lib/WebService/NoPaste.pm	Mon Dec 26 18:45:18 2005
@@ -3,7 +3,6 @@
 use LWP::UserAgent;
 use HTTP::Request::Common 'POST';
 use IO::All;
-use Clipboard;
 our $VERSION = '0.03';
 
 sub new {
@@ -37,9 +36,9 @@
     io('-')->all
 }
 
-sub read_from_clipboard { Clipboard->paste }
+sub read_from_clipboard { }
 
-sub save_to_clipboard { Clipboard->copy($_[0]); }
+sub save_to_clipboard { }
 
 my $PLEASE_EMAIL = "WebService::NoPaste has only been tested with 'pastebot' brand paste servers, and even then only to a limited extent.  If you got this error unexpectedly, please let me know - rking\@panopic.com.";
 sub response_die {
@@ -57,14 +56,6 @@
 
     # Manually paste input, manually copy the result url:
     $ nopaste
-
-    # Turbo mode: use clipboard as input, send, and then put the result
-    # URL back into the clipboard:
-    $ nopaste cp
-
-    # Just take the input from the clipboard, but otherwise leave the
-    # clipboard alone:
-    $ nopaste c
 
     # Instantly upload your passwd file for the whole world to see, but
     # at least you'll have the result URL conveniently in your
