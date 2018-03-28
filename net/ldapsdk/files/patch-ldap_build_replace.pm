--- ldap/build/replace.pm.orig	2011-01-06 12:05:39 UTC
+++ ldap/build/replace.pm
@@ -62,7 +62,7 @@ sub GenerateHeader ($$\%) {
     while(<TEMPLATE>) {
         my $line = $_;
         while(($orig, $replace) = each %$keywords) {
-            $line =~ s/{{$orig}}/$replace/g;
+            $line =~ s/\{\{$orig}}/$replace/g;
         }
 	
 	# the first line is a comment specific to the template file, which we
