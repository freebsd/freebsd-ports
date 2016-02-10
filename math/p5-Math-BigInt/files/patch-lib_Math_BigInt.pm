--- lib/Math/BigInt.pm.orig	2016-02-07 17:28:38 UTC
+++ lib/Math/BigInt.pm
@@ -65,7 +65,7 @@ use overload
 '>>='   =>      sub { $_[0]->brsft($_[1]); },
 
 # not supported by Perl yet
-'..'    =>      \&_pointpoint,
+#'..'    =>      \&_pointpoint,
 
 '<=>'   =>      sub { my $rc = $_[2] ?
                       ref($_[0])->bcmp($_[1],$_[0]) :
