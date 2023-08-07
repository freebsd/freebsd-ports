--- perl/Amanda/Status.pm.orig	2017-12-01 13:26:29 UTC
+++ perl/Amanda/Status.pm
@@ -890,7 +890,7 @@ REREAD:
 			    if (defined $dlet->{'status'} and 
 				($dlet->{'status'} != $WAIT_FOR_WRITING &&
 				 $dlet->{'status'} != $WRITE_FAILED)) {
-				die ("bad status on taper FILE-WRITE (writing): $dlet->{'status'}");
+				#die ("bad status on taper FILE-WRITE (writing): $dlet->{'status'}");
 			    }
 			    $dlet->{'status'} = $WRITING;
 			}
