 --- gman.pl.orig	Mon Sep  6 16:55:42 2004
 +++ gman.pl	Mon Sep  6 16:55:45 2004
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
 @@ -14,35 +14,43 @@
  }
  
  my $section = $ARGV[0]; # should also have some sanity check
 +my $cut = "/usr/bin/cut -f 1 -d \" \" ";
  my $name = $ARGV[1];
 -my $man2html = "/usr/lib/cgi-bin/man2html";
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
  	print <<end_of_line;
  Content-type: text/html
  
 -<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
 -<HTML><HEAD>
 -<TITLE>404 Not Found</TITLE>
 -</HEAD><BODY>
 +<!DOCTYPE html PUBLIC "-//IETF//DTD HTML 2.0//EN">
 +<html><head>
 +<title>404 Not Found</title>
 +</head><body>
  <H1>Not Found</H1>
  The requested man page $name($section) was not found on this server.
 -</BODY></HTML>
 +</body></html>
  end_of_line
 -	die;
 +;
  }
  
 -my $page = `$man2html $path`;
 +my $page = `$man $section $name |$man2html`;
  
  # $page =~ s/^Content-type: text\/html\n\n// if (not run as cgi...);
  
 -$page =~ s/(This document was created by\n<a HREF=\".*\">man2html<\/a>)(,\nusing the manual pages.<br>)/$1 for <a href=\"\/cgi-bin\/gman.pl?1+gman\">gman<\/a>$2/io;
 +print <<eof;
 +Content-type: text/html
 +
 +<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML//EN">
 +eof
 +;
  
  print $page;
 +
