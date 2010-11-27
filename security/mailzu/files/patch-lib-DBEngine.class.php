--- lib/DBEngine.class.php.orig	2010-11-24 11:32:33.000000000 +0100
+++ lib/DBEngine.class.php	2010-11-24 11:32:41.000000000 +0100
@@ -132,7 +132,7 @@
 			MAX(stattable.badheaders) AS badheaders,
 			MAX(stattable.pending) AS pending
 			FROM (
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					COUNT(content) AS spam,
 					0 AS banned,
 					0 AS viruses,
@@ -141,9 +141,9 @@
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					WHERE content='S' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					COUNT(content) AS banned,
 					0 AS viruses,
@@ -152,9 +152,9 @@
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					WHERE content='B' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
 					COUNT(content) AS viruses,
@@ -163,9 +163,9 @@
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					WHERE content='V' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
 					0 AS viruses,
@@ -174,9 +174,9 @@
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					WHERE content='H' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
 					0 AS viruses,
@@ -184,7 +184,7 @@
 					COUNT(content) AS pending
 					FROM msgs JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					WHERE msgrcpt.rs='p' AND NOT (msgs.quar_type = '')
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 			) AS stattable
 			GROUP BY date
 			ORDER BY date";
@@ -253,7 +253,7 @@
 			MAX(stattable.badheaders) AS badheaders,
 			MAX(stattable.pending) AS pending
 			FROM (
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					COUNT(content) AS spam,
 					0 AS banned,
 					0 AS viruses,
@@ -263,9 +263,9 @@
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
 					WHERE content='S' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					COUNT(content) AS banned,
 					0 AS viruses,
@@ -275,9 +275,9 @@
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
 					WHERE content='B' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
 					COUNT(content) AS viruses,
@@ -287,9 +287,9 @@
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
 					WHERE content='V' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
 					0 AS viruses,
@@ -299,9 +299,9 @@
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
 					WHERE content='H' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 				UNION
-				SELECT CAST(time_iso AS DATE) AS date,
+				SELECT CAST(FROM_UNIXTIME(time_num) AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
 					0 AS viruses,
@@ -311,7 +311,7 @@
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
 					WHERE msgrcpt.rs='p' AND NOT (msgs.quar_type = '')
 					AND $recipEmailClause
-					GROUP BY CAST(time_iso AS DATE)
+					GROUP BY CAST(FROM_UNIXTIME(time_num) AS DATE)
 			) AS stattable
 			GROUP BY date
 			ORDER BY date";
