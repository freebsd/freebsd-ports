--- config/make-jars.pl.orig	Wed Oct 13 16:17:11 2004
+++ config/make-jars.pl	Wed Oct 13 16:17:07 2004
@@ -40,6 +40,7 @@
   last if ($arg eq "--");
 }
 my $defines = join(' ', @ARGV[ $ddindex .. $#ARGV ]);
+splice @ARGV, $ddindex, $#ARGV;
 
 getopts("d:s:t:f:avlD:o:p:xz:");
 
