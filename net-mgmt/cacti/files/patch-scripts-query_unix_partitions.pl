--- scripts/query_unix_partitions.pl.orig	Sat Apr 15 22:25:55 2006
+++ scripts/query_unix_partitions.pl	Sat Apr 15 22:26:14 2006
@@ -5,7 +5,7 @@
 	exit;
 }
 
-open(DF, "/bin/df -P|");
+open(DF, "/bin/df -k|");
 
 while (<DF>) {
 	#/dev/hda2             20157744  18553884    579860  97% /var
