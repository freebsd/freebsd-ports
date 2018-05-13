--- perl/rackmonkey.pl.orig	2018-05-13 19:00:11 UTC
+++ perl/rackmonkey.pl
@@ -28,6 +28,8 @@ use 5.006_001;
 use HTML::Template;
 use HTML::Entities;
 use Time::Local;
+use FindBin;
+use lib "$FindBin::Bin/";
 
 use RackMonkey::CGI;
 use RackMonkey::Engine;
