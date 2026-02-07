--- lib/Crypt/RandPasswd.pm.orig	2011-08-19 17:39:52.000000000 -0400
+++ lib/Crypt/RandPasswd.pm	2011-08-19 17:40:47.000000000 -0400
@@ -1466,6 +1466,7 @@
 =cut
 
 sub random_chars_in_range($$$$) {
+     @_ > 4 and shift;
      my( $minlen, $maxlen, $lo_char, $hi_char ) = @_;
 
      $minlen <= $maxlen or die "minlen $minlen is greater than maxlen $maxlen";
