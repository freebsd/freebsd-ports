--- File/KGlob2RE.pm.orig	Wed Apr 17 13:05:33 2002
+++ File/KGlob2RE.pm	Wed Apr 17 13:06:10 2002
@@ -110,7 +110,7 @@
 	warn "Unexpected end of file glob pattern: $glob\n";
 	return undef;
     }
-    if(  $re !~ s-$NOQT/\(\|,\.\*/\)$-\1/-  ) {		# X/%*	-> ^X/
+    if(  $re !~ s-$NOQT/\(\|,\.\*/\)$-$1/-  ) {		# X/%*	-> ^X/
 	$re .= '$';
     } elsif(  "" eq $re  ) {	# Since m// means something else:
 	$re= "^";									# %/*	-> anything
