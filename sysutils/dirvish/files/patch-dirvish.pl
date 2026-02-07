--- dirvish.pl.orig	2009-04-14 10:31:56.499054436 -0400
+++ dirvish.pl	2009-04-14 10:32:25.597066893 -0400
@@ -935,14 +935,14 @@
 #	if ($A{dir} =~ /^:/)
 	if ($A{dir} !~ /^:/)
 	{
-		$rcmd = sprintf ("%s 'cd %s; %s %s' >>%s",
+		$rcmd = sprintf ("%s 'cd %s; env %s %s' >>%s",
 			("$A{shell}" || "/bin/sh -c"),
 			$A{dir}, $A{env},
 			$cmd,
 			$A{log}
 		);
 	} else {
-		$rcmd = sprintf ("%s '%s %s' >>%s",
+		$rcmd = sprintf ("%s 'env %s %s' >>%s",
 			("$A{shell}" || "/bin/sh -c"),
 			$A{env},
 			$cmd,
