Index: sysgather.pl
===================================================================
--- sysgather.pl	(revision 217)
+++ sysgather.pl	(revision 219)
@@ -211,7 +211,7 @@
 			die "No base directory $g->{basedir} for $pkg\n";
 		}
 		if (! -d $g->{'confdir'}) {
-			mkdir $g->{'confdir'} or
+			mkdir $g->{'confdir'}, 0777 or
 			    die "Could not create $g->{confdir}: $!\n";
 		}
 
@@ -269,7 +269,7 @@
 			die "No source directory $g->{srcdir} for $pkg\n";
 		}
 		if (! -d $g->{'confdir'}) {
-			mkdir $g->{'confdir'} or
+			mkdir $g->{'confdir'}, 0777 or
 			    die "Could not create $g->{confdir}: $!\n";
 		}
 
@@ -325,7 +325,7 @@
 			die "No base directory $g->{basedir} for $pkg\n";
 		}
 		if (! -d $g->{'confdir'}) {
-			mkdir $g->{'confdir'} or
+			mkdir $g->{'confdir'}, 0777 or
 			    die "Could not create $g->{confdir}: $!\n";
 		}
 
@@ -457,7 +457,7 @@
 			die "No source directory $g->{srcdir} for $pkg\n";
 		}
 		if (! -d $g->{'confdir'}) {
-			mkdir $g->{'confdir'} or
+			mkdir $g->{'confdir'}, 0777 or
 			    die "Could not create $g->{confdir}: $!\n";
 		}
 
