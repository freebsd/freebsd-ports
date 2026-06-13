--- lib/PLAAttribute.php.orig	2024-01-10 22:23:54 UTC
+++ lib/PLAAttribute.php
@@ -78,6 +78,9 @@ class PLAAttribute {
 	protected $autovalue = array();
 	protected $postvalue = array();
 
+	# php85
+	public $js = array();
+
 	public function __construct($name,$values,$server_id,$source=null) {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',5,0,__FILE__,__LINE__,__METHOD__,$fargs);
