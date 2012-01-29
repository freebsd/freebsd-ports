--- ./lib/readmail.pl.orig	2012-01-16 14:33:30.000000000 -0800
+++ ./lib/readmail.pl	2012-01-16 14:35:37.000000000 -0800
@@ -117,9 +117,9 @@
 ##  set to true.
 
 %MIMEDecoders			= ()
-    unless defined(%MIMEDecoders);
+    unless (%MIMEDecoders);
 %MIMEDecodersSrc		= ()
-    unless defined(%MIMEDecodersSrc);
+    unless (%MIMEDecodersSrc);
 
 ## - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 ##  %MIMECharSetConverters is the associative array for storing functions
@@ -153,9 +153,9 @@
 ##  string.
 
 %MIMECharSetConverters			= ()
-    unless defined(%MIMECharSetConverters);
+    unless (%MIMECharSetConverters);
 %MIMECharSetConvertersSrc		= ()
-    unless defined(%MIMECharSetConvertersSrc);
+    unless (%MIMECharSetConvertersSrc);
 
 ## - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 ##  %MIMEFilters is the associative array for storing functions that
@@ -180,9 +180,9 @@
 ##  that all functions are defined before invoking MAILread_body.
 
 %MIMEFilters	= ()
-    unless defined(%MIMEFilters);
+    unless (%MIMEFilters);
 %MIMEFiltersSrc	= ()
-    unless defined(%MIMEFiltersSrc);
+    unless (%MIMEFiltersSrc);
 
 ## - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 ##  %MIMEFiltersArgs is the associative array for storing any optional
@@ -196,7 +196,7 @@
 ##  listed for a function if both are applicable.
 
 %MIMEFiltersArgs	= ()
-    unless defined(%MIMEFiltersArgs);
+    unless (%MIMEFiltersArgs);
 
 ## - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 ##  %MIMEExcs is the associative array listing which data types
@@ -206,7 +206,7 @@
 ##	Values => <should evaluate to a true expression>
 
 %MIMEExcs			= ()
-    unless defined(%MIMEExcs);
+    unless (%MIMEExcs);
 
 ## - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 ##  %MIMEIncs is the associative array listing which data types
@@ -220,7 +220,7 @@
 ##  be used to only allow a well-defined set of content-types.
 
 %MIMEIncs			= ()
-    unless defined(%MIMEIncs);
+    unless (%MIMEIncs);
 
 ## - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 ##  %MIMECharsetAliases is a mapping of charset names to charset names.
@@ -231,7 +231,7 @@
 ##	Values => real charset name
 ##
 %MIMECharsetAliases = ()
-    unless defined(%MIMECharsetAliases);
+    unless (%MIMECharsetAliases);
 
 ##---------------------------------------------------------------------------
 ##	Text entity-related variables
