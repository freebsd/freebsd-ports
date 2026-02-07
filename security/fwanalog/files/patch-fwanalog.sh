--- fwanalog.sh.orig	Tue May 22 20:44:50 2007
+++ fwanalog.sh	Tue May 22 20:49:10 2007
@@ -993,7 +993,7 @@
     fi
 
     #               1      2      3     4           5             6        7         8     9         10    11       12	      13
-    $perl -pwe "s!^(\d+) +(\w+) +(\d+) ([0-9:]+) .+(Deny|Reject) ([\w-]+) ([0-9.]+):(\d*) ([0-9.]+):(\d*) ([\w-]+) ([\w-]+) ([\w-]+)\$!\$7 - - [\$3/\$2/\$1:\$4 $timezone] \"GET /$reqhost/\$6/\$10/ HTTP/1.0\" 200 1 \"http://\$8/\" \"\" 0 \$13 !" \$outdir/fwanalog.current.withyear > $outdir/fwanalog.current.log
+    $perl -pwe "s!^(\d+) +(\w+) +(\d+) ([0-9:]+) .+(Deny|Reject) ([\w-]+) ([0-9.]+):(\d*) ([0-9.]+):(\d*) ([\w-]+) ([\w-]+) ([\w-]+)\$!\$7 - - [\$3/\$2/\$1:\$4 $timezone] \"GET /$reqhost/\$6/\$10/ HTTP/1.0\" 200 1 \"http://\$8/\" \"\" 0 \$13 !" $outdir/fwanalog.current.withyear > $outdir/fwanalog.current.log
 
     # $outdir/fwanalog.current.log now contains the data in the Analog URL format.
 }
