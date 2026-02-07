--- install.php.orig	2016-04-08 09:51:58 UTC
+++ install.php
@@ -212,8 +212,8 @@ function parse_mysql_dump($url) {
 			if (trim($sql_line) != "" && strpos($sql_line, "--") === false) {
 				$query .= $sql_line;
 				if(preg_match("/;[\040]*\$/", $sql_line)) {
-					if (!$result = mysql_query($query)) {
-						echo mysql_error(); //Uncomment for debug
+					if (!$result = mysqli_query($GLOBALS["___mysqli_ston"], $query)) {
+						echo mysqli_error($GLOBALS["___mysqli_ston"]); //Uncomment for debug
 						echo "<i><br>$query<br></i>";
 						return 0;
 					}
@@ -426,7 +426,7 @@ function adjust_paths_for_freebsd($engin
 	for ($i = 0; $i < count ($adjust_sql); $i++) {
 		switch ($engine) {
 			case 'mysql':
-				$result = mysql_query($adjust_sql[$i]);
+				$result = mysqli_query($GLOBALS["___mysqli_ston"], $adjust_sql[$i]);
 				break;
 			case 'oracle':
 				//Delete the last semicolon from current query
@@ -575,7 +575,8 @@ function install_step2() {
 				font-size: 8.5pt;margin-top: 2px; font-weight: bolder;'>DB Engines</span>";
 			echo "</td><td>";
 			echo "</td></tr>";
-			check_extension("mysql", "PHP MySQL extension");
+			check_extension("mysql", "PHP mysql extension (deprecated)");
+			check_extension("mysqli", "PHP mysql extension");
 			check_extension("pgsql", "PHP PostgreSQL extension");
 			check_extension("oci8", "PHP Oracle extension");
 			echo "</table>";
@@ -617,8 +618,8 @@ function install_step2() {
 
 function install_step3() {
 	$options = '';
-	if (extension_loaded("mysql")) {
-		$options .= "<option value='mysql'>MySQL</option>";
+	if (extension_loaded("mysql") || extension_loaded("mysqli")) {
+		$options .= "<option value='mysql'>mysql</option>";
 	}
 	if (extension_loaded("pgsql")) {
 		$options .= "<option value='pgsql'>PostgreSQL</option>";
@@ -811,7 +812,7 @@ function install_step4() {
 			<table width='100%'>";
 			switch ($engine) {
 				case 'mysql':
-					if (! mysql_connect ($dbhost, $dbuser, $dbpassword)) {
+					if (! ($GLOBALS["___mysqli_ston"] = mysqli_connect($dbhost,  $dbuser,  $dbpassword))) {
 						check_generic ( 0, "Connection with Database");
 					}
 					else {
@@ -819,19 +820,19 @@ function install_step4() {
 						
 						// Drop database if needed and don't want to install over an existing DB
 						if ($dbdrop == 1) {
-							mysql_query ("DROP DATABASE IF EXISTS `$dbname`");
+							mysqli_query($GLOBALS["___mysqli_ston"], "DROP DATABASE IF EXISTS `$dbname`");
 						}
 						
 						// Create schema
 						if ($dbaction == 'db_new' || $dbdrop == 1) {
-							$step1 = mysql_query ("CREATE DATABASE `$dbname`");
+							$step1 = mysqli_query($GLOBALS["___mysqli_ston"], "CREATE DATABASE `$dbname`");
 							check_generic ($step1, "Creating database '$dbname'");
 						}
 						else {
 							$step1 = 1;
 						}
 						if ($step1 == 1) {
-							$step2 = mysql_select_db($dbname);
+							$step2 = mysqli_select_db($GLOBALS["___mysqli_ston"], $dbname);
 							check_generic ($step2, "Opening database '$dbname'");
 							
 							$step3 = parse_mysql_dump("pandoradb.sql");
@@ -848,9 +849,9 @@ function install_step4() {
 							$host = 'localhost';
 							if ($dbhost != 'localhost')
 								$host = $dbgrant;
-							$step5 = mysql_query ("GRANT ALL PRIVILEGES ON `$dbname`.* to pandora@$host 
+							$step5 = mysqli_query($GLOBALS["___mysqli_ston"], "GRANT ALL PRIVILEGES ON `$dbname`.* to pandora@$host 
 								IDENTIFIED BY '".$random_password."'");
-							mysql_query ("FLUSH PRIVILEGES");
+							mysqli_query($GLOBALS["___mysqli_ston"], "FLUSH PRIVILEGES");
 							check_generic ($step5, "Established privileges for user pandora. A new random password has been generated: <b>$random_password</b><div class='warn'>Please write it down, you will need to setup your Pandora FMS server, editing the </i>/etc/pandora/pandora_server.conf</i> file</div>");
 							
 							$step6 = is_writable("include");
@@ -863,7 +864,7 @@ function install_step4() {
 							$config_new = '<?php
 							// Begin of automatic config file
 							$config["dbtype"] = "' . $dbtype . '"; //DB type (mysql, postgresql...in future others)
-							$config["dbname"]="'.$dbname.'";			// MySQL DataBase name
+							$config["dbname"]="'.$dbname.'";			// mysql DataBase name
 							$config["dbuser"]="pandora";			// DB User
 							$config["dbpass"]="'.$random_password.'";	// DB Password
 							$config["dbhost"]="'.$dbhost.'";			// DB Host
@@ -1145,7 +1146,7 @@ function install_step4() {
 							$config_new = '<?php
 							// Begin of automatic config file
 							$config["dbtype"] = "' . $dbtype . '"; //DB type (mysql, postgresql...in future others)
-							$config["dbname"]="'.$dbname.'";			// MySQL DataBase name
+							$config["dbname"]="'.$dbname.'";			// mysql DataBase name
 							$config["dbuser"]="pandora";			// DB User
 							$config["dbpass"]="'.$random_password.'";	// DB Password
 							$config["dbhost"]="'.$dbhost.'";			// DB Host
@@ -1208,12 +1209,12 @@ function install_step4() {
 				
 				switch ($engine) {
 					case 'mysql':
-						if (mysql_error() != "") {
-							echo "<div class='err'> <b>ERROR:</b> ". mysql_error().".</div>";
+						if (mysqli_error($GLOBALS["___mysqli_ston"]) != "") {
+							echo "<div class='err'> <b>ERROR:</b> ". mysqli_error($GLOBALS["___mysqli_ston"]).".</div>";
 						}
 						
 						if ($step1 == 1) {
-							mysql_query ("DROP DATABASE $dbname");
+							mysqli_query($GLOBALS["___mysqli_ston"], "DROP DATABASE $dbname");
 						}
 						break;
 					case 'pgsql':
