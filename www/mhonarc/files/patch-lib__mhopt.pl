--- ./lib/mhopt.pl.orig	2012-01-16 14:32:41.000000000 -0800
+++ ./lib/mhopt.pl	2012-01-16 14:33:10.000000000 -0800
@@ -864,7 +864,7 @@
 ##
 sub update_data_2_1_to_later {
     # we can preserve filter arguments
-    if (defined(%main::MIMEFiltersArgs)) {
+    if (%main::MIMEFiltersArgs) {
 	warn qq/         preserving MIMEARGS...\n/;
 	%readmail::MIMEFiltersArgs = %main::MIMEFiltersArgs;
 	$IsDefault{'MIMEARGS'} = 0;
