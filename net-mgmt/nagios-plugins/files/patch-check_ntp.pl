--- plugins-scripts/check_ntp.pl.orig	Wed May 25 16:05:41 2005
+++ plugins-scripts/check_ntp.pl	Wed Aug  3 10:23:37 2005
@@ -309,7 +309,6 @@
 				}
 			} else {
 				print "No match!\n" if $verbose;
-				$jitter = '(not parsed)';
 			}
 			
 		}
