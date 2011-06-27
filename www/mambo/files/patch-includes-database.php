--- ./includes/database.php.orig	2011-06-27 12:26:39.000000000 +1000
+++ ./includes/database.php	2011-06-27 12:27:48.000000000 +1000
@@ -784,6 +784,10 @@
 	/** @var mosDatabase Database connector */
 	var $_db = null;
 
+	function mosDBTable ($table='', $keyname='id', $db='') { 
+        	$this->mosDBAbstractRow($table, $keyname, $db); 
+	} 
+
 	/**
 	 *	@return bool True if DB query failed.  Sets the error message
 	 */
