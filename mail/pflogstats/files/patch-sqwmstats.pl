--- sqwmstats.pl.orig	Fri Apr  4 15:29:35 2003
+++ sqwmstats.pl	Mon May 12 10:38:01 2003
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -W
+#!/usr/bin/perl
 
 ###
 # Project:     pflogstats
@@ -32,28 +32,27 @@
 ###
 
 
-use warnings;
 use strict;
 
 ## Name and version
-my $release = "0.03";
-our $progName = "sqwmstats.pl";
+use vars qw{$release $progName};
+$release = "0.03";
+$progName = "sqwmstats.pl";
 
 
 ## Define global variables
 
 # option handling
-our %options;
-our %opts;
+use vars qw{%options %opts};
 
 $options{'help|h|?'}  = \$opts{'help'};
 $options{"version"}  = \$opts{'version'};
 
 # module hooks
-our %hooks;
+use vars qw{%hooks};
 
 # Number formats
-our %numberformat;
+use vars qw{%numberformat};
 
 ## Module loader
 # General
