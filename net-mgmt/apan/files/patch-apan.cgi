
$FreeBSD$

--- apan.cgi.orig	Fri Jan 17 12:18:11 2003
+++ apan.cgi	Mon Mar 29 17:08:42 2004
@@ -1,11 +1,11 @@
-#!/bin/bash
+#!%%PREFIX%%/bin/bash
 # This file is used to generate the graphs. It should reside in
 # Nagios cgi-bin directory (Noramally the sbin-dir in your Nagios
 # installation).
 #
 #
 # Change this if you are not installing apan in /usr/local/nagios/apan
-DEFSFILE=/usr/local/nagios/apan/apan.defs
+DEFSFILE=%%APANCONFDIR%%/apan.defs
 #
 # Don't change anything below...
 #
@@ -63,38 +63,38 @@
 
 	if [ $N -ne 2 ]; then
 		echo "Statistics for the last 10 minutes:<BR>"
-		echo "<IMG SRC=generate.cgi?$HOST&$CHECK&600><BR>"
+		echo "<IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&600><BR>"
 		echo "Statistics for the last hour:<BR>"
-		echo "<IMG SRC=generate.cgi?$HOST&$CHECK&3600><BR>"
+		echo "<IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&3600><BR>"
 		echo "Statistics for the last 24 hours:<BR>"
-		echo "<IMG SRC=generate.cgi?$HOST&$CHECK&86400><BR>"
+		echo "<IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&86400><BR>"
 		echo "Statistics for the last week:<BR>"
-		echo "<IMG SRC=generate.cgi?$HOST&$CHECK&604800><BR>"
+		echo "<IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&604800><BR>"
 		echo "Statistics for the last Month:<BR>"
-		echo "<IMG SRC=generate.cgi?$HOST&$CHECK&2851200><BR>"
+		echo "<IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&2851200><BR>"
 		echo "Statistics for the last Year:<BR>"
-		echo "<IMG SRC=generate.cgi?$HOST&$CHECK&31557600><BR>"
+		echo "<IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&31557600><BR>"
 	else
 		echo "<TABLE COLS=2 BORDER=1>"
 		echo "<TR><TD COLSPAN=2>Statistics for the last 10 minutes:</TD></TR>"
-		echo "<TR><TD><IMG SRC=generate.cgi?$HOST&$CHECK&600&0></TD>"
-		echo "<TD><IMG SRC=generate.cgi?$HOST&$CHECK&300&1></TD></TR>"
+		echo "<TR><TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&600&0></TD>"
+		echo "<TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&300&1></TD></TR>"
 		echo "<TR><TD COLSPAN=2>Statistics for the last hour:</TD></TR>"
-		echo "<TR><TD><IMG SRC=generate.cgi?$HOST&$CHECK&3600&0></TD>"
-		echo "<TD><IMG SRC=generate.cgi?$HOST&$CHECK&3600&1></TD></TR>"
+		echo "<TR><TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&3600&0></TD>"
+		echo "<TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&3600&1></TD></TR>"
 		echo "<TR><TD COLSPAN=2>Statistics for the last 24 hours:</TD></TR>"
-		echo "<TR><TD><IMG SRC=generate.cgi?$HOST&$CHECK&86400&0><BR></TD>"
-		echo "<TD><IMG SRC=generate.cgi?$HOST&$CHECK&86400&1></TD></TR>"
+		echo "<TR><TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&86400&0><BR></TD>"
+		echo "<TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&86400&1></TD></TR>"
 		echo "<TR><TD COLSPAN=2>Statistics for the last week:</TD></TR>"
-		echo "<TR><TD><IMG SRC=generate.cgi?$HOST&$CHECK&604800&0></TD>"
-		echo "<TD><IMG SRC=generate.cgi?$HOST&$CHECK&604800&1></TD></TR>"
+		echo "<TR><TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&604800&0></TD>"
+		echo "<TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&604800&1></TD></TR>"
 
 		echo "<TR><TD COLSPAN=2>Statistics for the last month:</TD></TR>"
-		echo "<TR><TD><IMG SRC=generate.cgi?$HOST&$CHECK&2851200&0></TD>"
-		echo "<TD><IMG SRC=generate.cgi?$HOST&$CHECK&2851200&1></TD></TR>"
+		echo "<TR><TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&2851200&0></TD>"
+		echo "<TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&2851200&1></TD></TR>"
 		echo "<TR><TD COLSPAN=2>Statistics for the last year:</TD></TR>"
-		echo "<TR><TD><IMG SRC=generate.cgi?$HOST&$CHECK&31557600&0></TD>"
-		echo "<TD><IMG SRC=generate.cgi?$HOST&$CHECK&31557600&1></TD></TR>"
+		echo "<TR><TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&31557600&0></TD>"
+		echo "<TD><IMG SRC=/nagios/cgi-bin/generate.cgi?$HOST&$CHECK&31557600&1></TD></TR>"
 		echo "</TABLE>"
 	fi
 
