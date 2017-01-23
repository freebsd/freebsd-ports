--- extract_url.pl.orig	2017-01-18 14:59:52 UTC
+++ extract_url.pl
@@ -54,18 +54,7 @@ sub VERSION_MESSAGE {
 
 my $term_cols = 80;
 my ($term_rows, $term_wpix, $term_hpix);
-if (eval "use Term::Readkey") {
-    ($term_cols, $term_rows, $term_wpix, $term_hpix) = GetTerminalSize();
-} else {
-    require 'sys/ioctl.ph';
-    if (defined &TIOCGWINSZ and open(TTY, "+</dev/tty")) {
-        my $winsize = '';
-        unless (ioctl(TTY, &TIOCGWINSZ, $winsize)) {
-            die sprintf "$0: ioctl TIOCGWINSZ (%08x: $!)\n", &TIOCGWINSZ;
-        }
-        ($term_rows, $term_cols, $term_wpix, $term_hpix) = unpack('S4', $winsize);
-    }
-}
+require 'sys/ioctl.ph';
 my $list_width = $term_cols - 4; # 4 is for the border width on either side
 
 my %options;
