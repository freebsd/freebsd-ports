--- Template.pm.orig	Fri Jun 18 21:42:06 2004
+++ Template.pm	Fri Jun 25 13:33:50 2004
@@ -890,7 +890,9 @@
 use strict; # and no funny business, either.
 
 use Carp; # generate better errors with more context
+BEGIN { unshift(@INC, "%%PERL_INC%%"); }
 use File::Spec; # generate paths that work on all platforms
+shift(@INC);
 use Digest::MD5 qw(md5_hex); # generate cache keys
 
 # define accessor constants used to improve readability of array
