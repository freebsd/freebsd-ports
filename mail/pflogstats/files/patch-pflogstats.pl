--- pflogstats.pl.orig	Fri Apr  4 15:29:35 2003
+++ pflogstats.pl	Mon May 12 10:37:46 2003
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -W
+#!/usr/bin/perl
 
 ###
 # Project:     pflogstats
@@ -30,10 +30,7 @@
 # ***** Sorry for some coding confusion, this is a developer version *****
 
 # Minium required Perl version
-require 5.6.0;
-
-#use warnings; # to be done later
-#use strict; # to be done later
+require 5.00503;
 
 # Global used Perl modules
 use Time::Local;
@@ -43,8 +40,9 @@
 
 
 ## Name and version
-my $release = "20030404.AERAsec";
-our $progName = "pflogstats.pl";
+use vars qw{$release $progName};
+$release = "20030404.AERAsec";
+$progName = "pflogstats.pl";
 
 
 ## Defines before module loader
@@ -62,9 +60,7 @@
 ## Define global variables
 
 # option handling
-our %options;
-our %opts;
-our %types;
+use vars qw{%options %opts %types}; 
 
 # Default value
 $types{'default'} = 0;
@@ -73,11 +69,12 @@
 $types{'test_verp_mung'} = 0;
 
 # module hooks
-our %hooks;
+use vars qw{%hooks};
 
 # Format options
-our @opt_format; # from option parsing
-our %format; # used format
+use vars qw{@opt_format %format};
+# @opt_format; # from option parsing
+# %format; # used format
 
 my @opt_types;
 my $isoDateTime;
@@ -143,10 +140,10 @@
 #exit 0;
 
 # Number formats
-our %numberformat;
+use vars qw{%numberformat};
 
 # Time range of logdata
-our ($timemin, $timemax);
+use vars qw{$timemin, $timemax};
 my ($time);
 
 
