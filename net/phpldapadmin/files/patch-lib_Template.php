--- lib/Template.php.orig	2024-01-10 22:23:54 UTC
+++ lib/Template.php
@@ -58,6 +58,8 @@ class Template extends xmlTemplate {
 	# Template RDN attributes
 	private $rdn;
 
+	private $askcontainer;
+
 	public function __construct($server_id,$name='',$filename=null,$type=null,$id=null) {
 		parent::__construct($server_id,$name,$filename,$type,$id);
 
