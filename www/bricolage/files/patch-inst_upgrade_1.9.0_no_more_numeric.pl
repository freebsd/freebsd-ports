--- inst/upgrade/1.9.0/no_more_numeric.pl.orig	Thu Aug 18 08:20:34 2005
+++ inst/upgrade/1.9.0/no_more_numeric.pl	Thu Feb  9 02:17:16 2006
@@ -101,6 +101,12 @@ while (<OLD>) {
         $last =~ s/,$// if $_ =~ /^\);/;
     }
 
+    # Fix incompatible checks.
+    if (/ck_(?:story|media)__publish_status/) {
+        s/\(0\)::integer/FALSE/g;
+        s/\(1\)::integer/TRUE/g;
+    }
+
     # Print the previouis line.
     print NEW $last;
     $last = $_;
