--- gman.pl.orig	2011-08-26 13:11:36.331148726 -0700
+++ gman.pl	2011-08-26 13:52:56.017429820 -0700
@@ -15,13 +15,16 @@
 
 my $section = $ARGV[0]; # should also have some sanity check
 my $name = $ARGV[1];
-my $man2html = "/usr/lib/cgi-bin/man/man2html";
-my $path = `man -w $section $name`; chomp $path; $path =~ s/\s*$//;
+my $cut = "/usr/bin/cut -f 1 -d \" \" ";
+my $man = "/usr/bin/man";
+my $man2html = "/usr/local/bin/man2html";
+my $man2html_args =  "-nodepage ";
+my $path = `$man -w $section $name |$cut`; chomp $path; $path =~ s/\s*$//;
 
 unless (-s "$path") {
   warn "not -s $path\n";
   $name = lc $name;
-  $path = `man -w $section $name`; chomp $path; $path =~ s/\s*$//;
+  $path = `$man -w $section $name |$cut`; chomp $path; $path =~ s/\s*$//;
 }
 unless (-s "$path") {
   warn "not -s $path\n";
@@ -29,12 +32,12 @@
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
@@ -45,19 +48,19 @@
 Content-type: text/html
 
 <!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
-<HTML><HEAD>
-<TITLE>man2html missing</TITLE>
-</HEAD><BODY>
-<H1>man2html missing</H1>
+<html><head>
+<title>man2html missing</title>
+</head><body>
+<h1>man2html missing</h1>
 
 <p>You have to install <tt>man2html</tt> in order to use this mode in gman.
 
-</BODY></HTML>
+</body></html>
 end_of_line
 	die;
 }
 
-my $page = `$man2html $path`;
+my $page = `$man $section $name | man2html $man2html_args`;
 
 # $page =~ s/^Content-type: text\/html\n\n// if (not run as cgi...);
 
