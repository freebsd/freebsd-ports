--- lib/Sys/Filesystem.pm.orig	Fri May 26 12:06:39 2006
+++ lib/Sys/Filesystem.pm	Fri May 26 12:06:40 2006
@@ -108,7 +108,7 @@
 	# Invert logic for regular
 	if (exists $params->{regular}) {
 		delete $params->{regular};
-		$params->{regular} = undef;
+		$params->{special} = undef;
 	}
 
 	my @filesystems = ();
