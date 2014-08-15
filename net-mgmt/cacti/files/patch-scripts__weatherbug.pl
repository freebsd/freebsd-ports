--- ./scripts/weatherbug.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/weatherbug.pl	2014-08-11 18:37:08.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 $output = `/bin/bash -c 'wget --quiet -O - \"http:\/\/wisapidata.weatherbug.com\/WxDataISAPI\/WxDataISAPI.dll?Magic=10991&RegNum=3647055&ZipCode=17241&StationID=NWVLL&Units=0&Version=2.7&Fore=1&t=1015084854\/"'`;
 
