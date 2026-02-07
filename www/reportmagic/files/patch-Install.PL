--- Install.PL.orig	2003-04-02 02:21:00.000000000 -0700
+++ Install.PL	2014-05-29 11:23:05.000000000 -0700
@@ -59,13 +59,13 @@
 # example to use the version number in your path. 
 # Make sure this remains in single quotes.
 #
-$DEST = '/usr/local/bin/rmagic-$(VERSION)/';
+$DEST = "$ENV{'DESTDIR'}$ENV{'PREFIX'}/reportmagic/";
  
 #
 # Where do you want documentation to be installed?
 # You can use string concatenation, as in this example, 
 # to install the docs below the program.
-$DOC = $DEST . 'docs/';
+$DOC = "$ENV{'DESTDIR'}$ENV{'PREFIX'}/share/doc/reportmagic/";
 
 
 #
@@ -269,7 +269,6 @@
 	$DOC = 'docs/' if defined $args{only_modules};
 	print "\nInstallation complete.\n";
 	print "For help on using Report Magic see $DOC"."index.html.\n";
-	print "You must agree to the license agreement at $DOC"."license.html before using Report Magic.\n";
 } # end if
 
 
@@ -305,7 +304,6 @@
 			chmod( $mode, $dest );
 		} else {
 			print "\t***Error: Can not copy $src to $dest. $!.\n";
-			$rc = 0;
 		} # end if
 	} # end if
 	return $rc;
