--- makepatch.PL	Sun Dec  6 09:04:51 1998
+++ makepatch.PL.new	Mon Nov  5 19:47:17 2001
@@ -670,11 +670,14 @@
 	$skipped++;
 	return 0;
     }
-    if ( -B $fh ) {
-	verbose ("WARNING: Binary file $new -- skipped\n");
-	$skipped++;
-	return 0;
-    }
+#  Binary/Text test on filehandle makes no sense (and causes failure)
+#  on FreeBSD
+#
+#    if ( -B $fh ) {
+#	verbose ("WARNING: Binary file $new -- skipped\n");
+#	$skipped++;
+#	return 0;
+#    }
     my $pos = $fh->getpos;
     while ( <$fh> ) {
 	$lines++;
