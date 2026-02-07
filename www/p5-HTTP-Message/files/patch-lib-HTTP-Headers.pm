--- lib/HTTP/Headers.pm.orig	2015-07-09 00:23:53 UTC
+++ lib/HTTP/Headers.pm
@@ -151,7 +151,7 @@ sub _header
     my($self, $field, $val, $op) = @_;
 
     Carp::croak("Illegal field name '$field'")
-        if rindex($field, ':') > 1 || !length($field);
+        if ( $field !~ /^X-Meta/ && rindex($field, ':') > 1) || !length($field);
 
     unless ($field =~ /^:/) {
 	$field =~ tr/_/-/ if $TRANSLATE_UNDERSCORE;
