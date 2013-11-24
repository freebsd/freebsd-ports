--- ./archive2.pl.orig	2013-11-24 18:52:35.932149986 +0400
+++ ./archive2.pl	2013-11-24 18:49:56.000000000 +0400
@@ -74,7 +74,7 @@
 
 # All these should be in the standard PERL library
 unshift(@INC, $homedir);
-require "ctime.pl";		# To get MoY definitions for month abbrevs
+use POSIX qw(ctime);
 require "majordomo_version.pl";	# What version of Majordomo is this?
 require "majordomo.pl";		# all sorts of general-purpose Majordomo subs
 require "shlock.pl";		# NNTP-style file locking
@@ -85,7 +85,7 @@
 
 # Here's where the fun begins...
 
-require "getopts.pl";
+use Getopt::Std;
 
 $m = 1;
 foreach (@ctime'MoY) {
@@ -94,7 +94,7 @@
 
 $usage = "Usage: $0 -f <file> {-u|-a} [-d|-D|-m|-M|-y|-Y] [file ...]";
 
-&Getopts("f:uadDmMyY") || die("$usage\nStopped");
+getopts("f:uadDmMyY") || die("$usage\nStopped");
 
 if (!defined($opt_f)) {
     print STDERR "'-f <list>' required\n$usage\n";
