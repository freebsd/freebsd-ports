--- ../Mail-ClamAV-0.05.orig/ClamAV.pm	Mon Feb 23 16:04:36 2004
+++ ClamAV.pm	Mon Feb 23 16:05:17 2004
@@ -138,12 +138,9 @@
     VERSION  => $VERSION,
     PREFIX   => 'clamav_perl_',
     NAME     => "Mail::ClamAV",
-    LIBS     => "-lclamav";
-# removed on install
-BEGIN {
-require "./config.pl";
-}
-# end removed on install
+    OPTIMIZE => '-g',
+    LIBS     => " -lclamav";
+
 use Inline C => <<'END_OF_C';
 #include <stdio.h>
 #include <string.h>
