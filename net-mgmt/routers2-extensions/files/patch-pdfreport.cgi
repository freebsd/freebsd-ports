--- pdfreport.cgi.orig	2012-09-19 02:32:33 UTC
+++ pdfreport.cgi
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -w
+#!%%LOCALBASE%%/bin/speedy -- -M20 -t3600 -gnone -r500
 # vim:ts=4
 # pdfreport.cgi
 #
@@ -13,11 +13,11 @@ use FileHandle;
 require 5.006;
 
 # Configure here
-my( $HTMLDOC ) = "/usr/bin/htmldoc"; # location of htmldoc executable
-my( $ROUTERSCGI ) = "/u01/www/cgi-bin/routers2.cgi"; # location of routers2.cgi
+my( $HTMLDOC ) = "%%LOCALBASE%%/bin/htmldoc"; # location of htmldoc executable
+my( $ROUTERSCGI ) = "%%LOCALBASE%%/www/routers2/routers2.cgi"; # location of routers2.cgi
 my( $WORKDIR ) = "/tmp";             # temporary work directory
-my( $WEBROOT ) = "/u01/www/html";    # docroot for your web server
-my( $CONFPATH ) = "/u01/mrtg/conf";  # default path for cfg files
+my( $WEBROOT ) = "%%LOCALBASE%%/www/data";    # docroot for your web server
+my( $CONFPATH ) = "%%LOCALBASE%%/etc@/mrtg";  # default path for cfg files
 my( $VERSION ) = "1.6";
 my( $DWMY ) = "my";                  # set to dw for short term graphs
 
