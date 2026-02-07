--- lib/DBEngine.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/DBEngine.class.php
@@ -67,7 +67,7 @@ class DBEngine {
 	* DBEngine constructor to initialize object
 	* @param none
 	*/
-	function DBEngine() {
+	function __construct() {
 		global $conf;
 
 		$this->dbType = $conf['db']['dbType'];
@@ -133,35 +133,35 @@ class DBEngine {
 			MAX(stattable.pending) AS pending
 			FROM (
 				SELECT CAST(time_iso AS DATE) AS date,
-					COUNT(content) AS spam,
+					COUNT(msgs.content) AS spam,
 					0 AS banned,
 					0 AS viruses,
 					0 AS badheaders,
 					0 AS pending
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
-					WHERE content='S' AND NOT (msgs.quar_type = '')
+					WHERE msgs.content='S' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
 				SELECT CAST(time_iso AS DATE) AS date,
 					0 AS spam,
-					COUNT(content) AS banned,
+					COUNT(msgs.content) AS banned,
 					0 AS viruses,
 					0 AS badheaders,
 					0 AS pending 
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
-					WHERE content='B' AND NOT (msgs.quar_type = '')
+					WHERE msgs.content='B' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
 				SELECT CAST(time_iso AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
-					COUNT(content) AS viruses,
+					COUNT(msgs.content) AS viruses,
 					0 AS badheaders,
 					0 AS pending
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
-					WHERE content='V' AND NOT (msgs.quar_type = '')
+					WHERE msgs.content='V' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
@@ -169,10 +169,10 @@ class DBEngine {
 					0 AS spam,
 					0 AS banned,
 					0 AS viruses,
-					COUNT(content) AS badheaders,
+					COUNT(msgs.content) AS badheaders,
 					0 AS pending
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
-					WHERE content='H' AND NOT (msgs.quar_type = '')
+					WHERE msgs.content='H' AND NOT (msgs.quar_type = '')
 					AND msgrcpt.rs IN ('','v')
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
@@ -181,7 +181,7 @@ class DBEngine {
 					0 AS banned,
 					0 AS viruses,
 					0 AS badheaders,
-					COUNT(content) AS pending
+					COUNT(msgs.content) AS pending
 					FROM msgs JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					WHERE msgrcpt.rs='p' AND NOT (msgs.quar_type = '')
 					GROUP BY CAST(time_iso AS DATE)
@@ -240,7 +240,7 @@ class DBEngine {
 		$recipEmailClause =  $this->convertEmailaddresses2SQL($emailaddresses);
 
 		# mysql seems to run faster with a left join
-		if ($conf['db']['dbtype'] == 'mysql') {
+		if ($conf['db']['dbType'] == 'mysql') {
 			$join_type = ' LEFT JOIN';
 		} else {
 			$join_type = ' INNER JOIN';
@@ -254,38 +254,38 @@ class DBEngine {
 			MAX(stattable.pending) AS pending
 			FROM (
 				SELECT CAST(time_iso AS DATE) AS date,
-					COUNT(content) AS spam,
+					COUNT(msgs.content) AS spam,
 					0 AS banned,
 					0 AS viruses,
 					0 AS badheaders,
 					0 AS pending
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
-					WHERE content='S' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
+					WHERE msgs.content='S' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
 				SELECT CAST(time_iso AS DATE) AS date,
 					0 AS spam,
-					COUNT(content) AS banned,
+					COUNT(msgs.content) AS banned,
 					0 AS viruses,
 					0 AS badheaders,
 					0 AS pending 
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
-					WHERE content='B' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
+					WHERE msgs.content='B' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
 				SELECT CAST(time_iso AS DATE) AS date,
 					0 AS spam,
 					0 AS banned,
-					COUNT(content) AS viruses,
+					COUNT(msgs.content) AS viruses,
 					0 AS badheaders,
 					0 AS pending
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
-					WHERE content='V' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
+					WHERE msgs.content='V' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
@@ -293,11 +293,11 @@ class DBEngine {
 					0 AS spam,
 					0 AS banned,
 					0 AS viruses,
-					COUNT(content) AS badheaders,
+					COUNT(msgs.content) AS badheaders,
 					0 AS pending
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
-					WHERE content='H' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
+					WHERE msgs.content='H' AND NOT (msgs.quar_type = '') AND msgrcpt.rs IN ('','v')
 					AND $recipEmailClause
 					GROUP BY CAST(time_iso AS DATE)
 				UNION
@@ -306,7 +306,7 @@ class DBEngine {
 					0 AS banned,
 					0 AS viruses,
 					0 AS badheaders,
-					COUNT(content) AS pending
+					COUNT(msgs.content) AS pending
 					FROM msgs INNER JOIN msgrcpt ON msgs.mail_id=msgrcpt.mail_id
 					$join_type maddr AS recip ON msgrcpt.rid=recip.id
 					WHERE msgrcpt.rs='p' AND NOT (msgs.quar_type = '')
@@ -606,7 +606,7 @@ class DBEngine {
 	*/
 	function get_raw_mail($mail_id, $email_recip) {
 		global $conf;
-
+		$ret_text = "";
 		$mail_text_column = ' mail_text';
 		# If using the bytea or BLOB type for sql quarantine use proper conversion
 		# (since amavisd 2.4.4
@@ -642,12 +642,12 @@ class DBEngine {
                         return false;
                 }
                 while ($rs = $result->fetchRow()) {
-                        $return .= $rs['mail_text'];
+                        $ret_text .= $rs['mail_text'];
                 }
                 
                 $result->free();
                 
-                return $return;
+                return $ret_text;
         }
 		
 	/**
