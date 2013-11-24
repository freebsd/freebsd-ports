--- ./md-sub/md-sub.cgi.orig	2013-11-24 18:54:07.634476295 +0400
+++ ./md-sub/md-sub.cgi	2013-11-24 18:47:15.000000000 +0400
@@ -78,7 +78,7 @@
 #
 # Required file
 require 'cgi-lib.pl';
-require 'getopts.pl';
+use Getopt::Std;
 
 #
 # Version number
@@ -90,7 +90,7 @@
 
 #
 # Call Getopts
-&Getopts( 'C:v');
+getopts( 'C:v');
 
 #
 # Check to see if we are creating a DB
