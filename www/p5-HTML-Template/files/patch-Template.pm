--- Template.pm.orig	Tue Feb 19 22:15:56 2002
+++ Template.pm	Tue Feb 19 22:18:31 2002
@@ -863,7 +863,9 @@
 use strict; # and no funny business, either.
 
 use Carp; # generate better errors with more context
+BEGIN { unshift(@INC, "%%PERL_INC%%"); }
 use File::Spec; # generate paths that work on all platforms
+shift(@INC);
 
 # define accessor constants used to improve readability of array
 # accesses into "objects".  I used to use 'use constant' but that
