--- lib/Query.php.orig	2024-01-10 22:23:54 UTC
+++ lib/Query.php
@@ -15,6 +15,14 @@ class Query extends xmlTemplate {
 class Query extends xmlTemplate {
 	protected $description = '';
 	public $results = array();
+	public $base = "";
+	public $dn = "";
+	public $filter = "";
+	public $icon = "";
+	public $resultsdata = array();
+	public $scope = "";
+	public $title = "";
+	public $visible = "";
 
 	/**
 	 * Main processing to store the template.
