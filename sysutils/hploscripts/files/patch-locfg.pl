--- ./locfg.pl.orig	2012-04-18 09:45:56.000000000 +0200
+++ ./locfg.pl	2012-04-18 09:46:13.000000000 +0200
@@ -143,7 +143,7 @@
         $ln =~ s/\r|\n//g;
 
         # Find LOGIN tag.
-        if ((($ln =~ ?<[ 	]*LOGIN[ 	]?) || ($ln =~ ?<[ 	]*LOGIN$?)) && ($pword) && ($uname)) {
+        if ((($ln =~m ?<[ 	]*LOGIN[ 	]?) || ($ln =~m ?<[ 	]*LOGIN$?)) && ($pword) && ($uname)) {
            while( !($ln =~ m/\>/i) ) {
               $ln = <F>;
            }
