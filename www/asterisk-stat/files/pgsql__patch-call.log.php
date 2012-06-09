--- call-log.php.orig	2012-04-05 10:48:18.000000000 +0300
+++ call-log.php	2012-04-05 10:48:29.000000000 +0300
@@ -229,7 +229,7 @@
 	
 	
 	/************************/
-	$QUERY = "SELECT substring(calldate,1,10) AS day, sum(duration) AS calltime, count(*) as nbcall FROM cdr WHERE ".$FG_TABLE_CLAUSE." GROUP BY substring(calldate,1,10)"; //extract(DAY from calldate) 
+	$QUERY = "SELECT cast(calldate as date) AS day, sum(duration) AS calltime, count(*) as nbcall FROM cdr WHERE ".$FG_TABLE_CLAUSE." GROUP BY cast(calldate as date) order by 1 desc"; //extract(DAY from calldate)
 	//echo "$QUERY";
