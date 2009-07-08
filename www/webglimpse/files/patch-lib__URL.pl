--- ./lib/URL.pl.orig	1998-01-09 00:58:41.000000000 -0500
+++ ./lib/URL.pl	2009-07-07 22:30:26.519067045 -0400
@@ -49,7 +49,10 @@
 	    $host =~ tr/A-Z/a-z/;
 	    $port = ($3 ne "" ? $3 : $ftp_port);
 	    $path = $4; 
-	    if ($userstring =~ /(.*):(.*)@/) {
+	    if (!defined($userstring)) {
+		$userid = undef;
+		$passwd = undef;
+	    } elsif ($userstring =~ /(.*):(.*)@/) {
 		$userid = $1;
 		$passwd = $2;
 	    } else {
@@ -102,7 +105,7 @@
 # URL of type: http://host[:port]/path[?search-string]
 
     if ($protocol eq "http") {
-	if ($url =~ m#^\s*\w+://([\w-\.]+):?(\d*)([^ \t]*)$#) {
+	if ($url =~ m#^\s*\w+://([\w\-\.]+):?(\d*)([^ \t]*)$#) {
 	    $server = $1;
 	    $server =~ tr/A-Z/a-z/;
 	    $port = ($2 ne "" ? $2 : $http_port);
@@ -137,7 +140,7 @@
 # URL of type: gopher://host[:port]/[gtype]selector-string[?search-string]
 
     if ($protocol eq "gopher") {
-	if ($url =~ m#^\s*\w+://([\w-\.]+):?(\d*)/?(\w?)([^ \t\?]*)\??(.*)$#) {
+	if ($url =~ m#^\s*\w+://([\w\-\.]+):?(\d*)/?(\w?)([^ \t\?]*)\??(.*)$#) {
 	    $server = $1;
 	    $server =~ tr/A-Z/a-z/;
 	    $port = ($2 ne "" ? $2 : $gopher_port);
@@ -152,7 +155,7 @@
 # URL of type: wais://host[:port]/database?search-string
 
     if ($protocol eq "wais") {
-	if ($url =~ m#^\s\w+://([\w-\.]+):?(\d*)/?([^\?]+)\??(.*)$#) {
+	if ($url =~ m#^\s\w+://([\w\-\.]+):?(\d*)/?([^\?]+)\??(.*)$#) {
 	    $1 =~ tr/A-Z/a-z/;
 	    $server = $1;
 	    $port = (defined($2) ? $2 : $wais_port);
