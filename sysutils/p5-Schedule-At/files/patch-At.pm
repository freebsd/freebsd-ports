--- At.pm.orig	Tue Sep 13 16:11:36 2005
+++ At.pm	Sun Nov 19 21:58:16 2006
@@ -55,6 +55,7 @@
 		print ATCMD "$TAGID$params{TAG}\n" if $params{TAG};
 		print ATCMD $params{COMMAND};
 		close (ATCMD);
+		return 1 if ($?);
 	}
 
 	0;
