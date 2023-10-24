--- lib/TemplateRender.php.orig	2023-04-01 13:46:16 UTC
+++ lib/TemplateRender.php
@@ -16,6 +16,9 @@ class TemplateRender extends PageRender {
 	# Page number
 	private $pagelast;
 
+	private $url_base;
+	private $layout;
+
 	/** CORE FUNCTIONS **/
 
 	/**
