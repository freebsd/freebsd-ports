--- majordomo.pl.orig	2011-03-08 14:26:57.730103144 +0100
+++ majordomo.pl	2011-03-08 14:27:45.390265818 +0100
@@ -44,7 +44,7 @@
 
 sub main'ParseMailHeader  ## Public
 {
-    local($save1, $save2) = ($*, $/);
+    local($save) = ($/);
     local($FH, *array) =  @_;
     local ($keyw, $val);
 
@@ -54,7 +54,7 @@
     local($package) = caller;
     $FH =~ s/^[^':]+$/$package'$&/;
 
-    ($*, $/) = (1, '');
+    $/ = '';
     $array = $_ = <$FH>;
     s/\n\s+/ /g;
        
@@ -69,7 +69,7 @@
 	    $array{$keyw} = $val;
 	}
     }
-    ($*, $/) = ($save1, $save2); 
+    $/ = $save; 
 }
 
 
@@ -95,14 +95,14 @@
     local($_) = shift;
     1 while s/\([^\(\)]*\)//g; 		# strip comments
     1 while s/"[^"]*"\s//g;		# strip comments"
-    split(/,/);				# split into parts
-    foreach (@_) {
+    my @parts = split(/,/);		# split into parts
+    foreach (@parts) {
 	1 while s/.*<(.*)>.*/$1/;
 	s/^\s+//;
 	s/\s+$//;
     }
 
-    @_;
+    @parts;
 }
 
 # Check to see if a list is valid.  If it is, return the validated list
