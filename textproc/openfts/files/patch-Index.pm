--- OpenFTS/Index.pm.orig	Wed Jul 24 02:15:37 2002
+++ OpenFTS/Index.pm	Tue Aug 19 20:28:53 2003
@@ -201,7 +201,7 @@
 	
 	foreach my $i ( 0..$#{$rv} ) {
 		my $param = $rv->[$i]{param};
-		if ( length $param ) {
+		if ( $param and length $param ) {
 			$rv->[$i]{param} = eval $param;
 			die "Can't eval '$param': $@" if $@;
 		}
