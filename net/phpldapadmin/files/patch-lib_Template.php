--- lib/Template.php.orig	2023-04-01 13:46:16 UTC
+++ lib/Template.php
@@ -56,6 +56,8 @@ class Template extends xmlTemplate {
 	# Template RDN attributes
 	private $rdn;
 
+	private $askcontainer;
+
 	public function __construct($server_id,$name='',$filename=null,$type=null,$id=null) {
 		parent::__construct($server_id,$name,$filename,$type,$id);
 
