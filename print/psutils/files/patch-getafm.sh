--- getafm.sh.orig	2013-04-23 16:38:17.000000000 +0900
+++ getafm.sh	2013-04-23 16:38:24.000000000 +0900
@@ -1,7 +1,7 @@
 #!/bin/sh
 
 if [ $# -ne 1 ]; then
-  echo "usage: $0 font-name | gsnd - >font-name.afm" >&2
+  echo "usage: $0 font-name | gsnd -q - >font-name.afm" >&2
   exit 1
 fi
 
@@ -13,6 +13,11 @@
 %	getafm 1.00 (c) AJCD
 % and getafm.ps by an unknown author,
 %	modified by J. Daniel Smith <dsmith@mailhost.aa.cad.slb.com>
+%
+% modified by Joachim H. Kaiser <jhk@cmpnetmail.com>:
+% - suggest a quiet gs run in usage
+% - get font version info (from 'version', not 'Version')
+% - add copyright field to output
 
 % Metrics dictionary code added by AJCD, 7/6/93
 
@@ -66,8 +71,9 @@
 	(isFixedPitch)(IsFixedPitch) prany
 	(UnderlinePosition)dup prany
 	(UnderlineThickness)dup prany
-	(Version)(version) prany
+	(version)(Version) prany
 	(Notice)dup prany
+	(Copyright)dup prany
       pop
     }
     {
