--- lib/page.php.orig	2023-04-01 13:46:16 UTC
+++ lib/page.php
@@ -25,6 +25,10 @@ class page {
 	# Default values array.
 	protected $_default;
 
+	private $index;
+	private $sysmsg;
+	private $_block;
+
 	public function __construct($index=null) {
 		if (defined('DEBUG_ENABLED') && DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',129,0,__FILE__,__LINE__,__METHOD__,$fargs);
