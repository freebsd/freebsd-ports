--- gman.pl.orig	2011-08-25 13:06:54.517309488 -0700
+++ gman.pl	2011-08-25 13:12:49.444936858 -0700
@@ -1,10 +1,10 @@
 #!/usr/bin/perl -w
-use strict;
 
 if (@ARGV != 2) {
   print <<_EOF_;
 Content-type: text/html
 
+<!DOCTYPE html PUBLIC "-//IETF//DTD HTML 2.0//EN">
 <html><head><title>gman.pl: invalid use</title></head>
 <body>
 <h1>gman.pl cannot be used without arguments.</h1>
@@ -14,14 +14,16 @@
 }
 
 my $section = $ARGV[0]; # should also have some sanity check
+my $cut = "/usr/bin/cut -f 1 -d \" \" ";
 my $name = $ARGV[1];
-my $man2html = "/usr/lib/cgi-bin/man/man2html";
-my $path = `man -w $section $name`; chomp $path; $path =~ s/\s*$//;
+my $man = "/usr/bin/man";
+my $man2html = "/usr/local/bin/man2html -nodepage ";
+my $path = `$man -w $section $name |$cut`; chomp $path; $path =~ s/\s*$//;
 
 unless (-s "$path") {
   warn "not -s $path\n";
   $name = lc $name;
-  $path = `man -w $section $name`; chomp $path; $path =~ s/\s*$//;
+  $path = `$man -w $section $name |$cut`; chomp $path; $path =~ s/\s*$//;
 }
 unless (-s "$path") {
   warn "not -s $path\n";
@@ -29,12 +31,12 @@
 Content-type: text/html
 
 <!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
-<HTML><HEAD>
-<TITLE>404 Not Found</TITLE>
-</HEAD><BODY>
-<H1>Not Found</H1>
+<html><head>
+<title>404 Not Found</title>
+</head><body>
+<h1>Not Found</h1>
 The requested man page $name($section) was not found on this server.
-</BODY></HTML>
+</body></html>
 end_of_line
 	die;
 }
@@ -44,15 +46,9 @@
 	print <<end_of_line;
 Content-type: text/html
 
-<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
-<HTML><HEAD>
-<TITLE>man2html missing</TITLE>
-</HEAD><BODY>
-<H1>man2html missing</H1>
-
-<p>You have to install <tt>man2html</tt> in order to use this mode in gman.
+<!DOCTYPE html PUBLIC "-//IETF//DTD HTML 2.0//EN">
 
-</BODY></HTML>
+</body></html>
 end_of_line
 	die;
 }
