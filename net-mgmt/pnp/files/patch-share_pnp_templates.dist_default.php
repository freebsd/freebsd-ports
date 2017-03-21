--- share/pnp/templates.dist/default.php.orig	2017-03-21 13:39:25 UTC
+++ share/pnp/templates.dist/default.php
@@ -47,7 +47,7 @@ foreach ($this->DS as $KEY=>$VAL) {
 		$crit_min = $VAL['CRIT_MIN'];
 	}
 	if ( $VAL['MIN'] != "" && is_numeric($VAL['MIN']) ) {
-		$lower = " --lower=" . $VAL['MIN'];
+		$lower = " --lower-limit=" . $VAL['MIN'];
 		$minimum = $VAL['MIN'];
 	}
 	if ( $VAL['MAX'] != "" && is_numeric($VAL['MAX']) ) {
@@ -55,8 +55,8 @@ foreach ($this->DS as $KEY=>$VAL) {
 	}
 	if ($VAL['UNIT'] == "%%") {
 		$vlabel = "%";
-		$upper = " --upper=101 ";
-		$lower = " --lower=0 ";
+		$upper = " --upper-limit=101 ";
+		$lower = " --lower-limit=0 ";
 	}
 	else {
 		$vlabel = $VAL['UNIT'];
