--- plugins-scripts/check_breeze.pl.orig	Tue May  7 07:35:49 2002
+++ plugins-scripts/check_breeze.pl	Fri Jul 19 20:46:00 2002
@@ -1,9 +1,9 @@
-#! /usr/bin/perl -wT
+#! /usr/bin/perl -w
 
 
 use strict;
 use Getopt::Long;
-use vars qw($opt_V $opt_h $opt_H $opt_w $opt_c $PROGNAME);
+use vars qw($opt_V $opt_h $opt_H $opt_w $opt_c $opt_C $PROGNAME);
 use lib utils.pm ;
 use utils qw(%ERRORS &print_revision &support &usage);
 
@@ -47,7 +47,7 @@
 ($opt_C) || ($opt_C = "public") ;
 
 my $sig=0;
-$sig = `/usr/bin/snmpget $host $opt_C .1.3.6.1.4.1.710.3.2.3.1.3.0`;
+$sig = `/usr/bin/snmpget -c $opt_C $host .1.3.6.1.4.1.710.3.2.3.1.3.0`;
 my @test=split(/ /,$sig);
 $sig=$test[2];
 $sig=int($sig);
