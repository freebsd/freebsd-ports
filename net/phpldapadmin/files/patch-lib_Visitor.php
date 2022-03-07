--- lib/Visitor.php.orig	2021-12-12 02:35:51 UTC
+++ lib/Visitor.php
@@ -22,6 +22,15 @@ abstract class Visitor {
 	protected $server_id;
 
 	public function __call($method,$args) {
+		# This mapping array allows to map effective class names to
+		# function name suffixes.
+		# It has been introduced when class Attribute has been renamed
+		# to PLAAttribute to avoid a name clash with the built-in
+		# class of PHP 8.
+		# Entering a class name mapping here allows to rename the
+		# class without having to rename the methods too.
+		static $classmap = array('PLAAttribute' => 'Attribute');
+
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',129,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
@@ -33,19 +42,14 @@ abstract class Visitor {
 		$fnct = array_shift($args);
 
 		$object = $args[0];
-		$class = get_class($object);
 
-		$call = "$method$fnct$class";
-
-		array_push($methods,$call);
-
-		while ($class && ! method_exists($this,$call)) {
+		for ($class = get_class($object); $class; $class = get_parent_class($class)) {
+			$call = isset($classmap[$class])? "$method$fnct$classmap[$class]": "$method$fnct$class";
+			array_push($methods,$call);
+			if (method_exists($this,$call))
+				break;
 			if (defined('DEBUGTMP') && DEBUGTMP)
 				printf('<font size=-2><i>Class (%s): Method doesnt exist (%s,%s)</i></font><br />',$class,get_class($this),$call);
-
-			$class = get_parent_class($class);
-			$call = "$method$fnct$class";
-			array_push($methods,$call);
 		}
 
 		if (defined('DEBUGTMP') && DEBUGTMP)
