--- dnsmap-bulk.sh.orig	2016-04-11 23:06:01 UTC
+++ dnsmap-bulk.sh
@@ -1,5 +1,5 @@
-#!/bin/bash
-if [[ $# -ne 1 && $# -ne 2 ]]
+#!/bin/sh
+if [ $# -ne 1 -a $# -ne 2 ]
 then
 	echo "usage: `basename $0` <domains-file> [results-path]";
 	echo "e.g.:";
@@ -9,10 +9,10 @@ then
 fi
 for i in `cat $1`
 do
-	if [[ $# -eq 1 ]] 
+	if [ $# -eq 1 ] 
 	then	
 		dnsmap $i
-	elif [[ $# -eq 2 ]]
+	elif [ $# -eq 2 ]
 	then
 		dnsmap $i -r $2
 	fi
