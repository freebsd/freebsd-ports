--- open/log/index.php.orig	2016-06-20 16:09:43 UTC
+++ open/log/index.php
@@ -18,7 +18,7 @@
 // === Print svn log --xml to response ===
 
 // Set the URL to the stylesheet, must be same host or absolute path from root
-$xslt = '/repos-web/view/log.xsl';
+$xslt = '/repos-style/view/log.xsl';
 
 // URL or path to repository, no trailing slash
 // (note that the log viewer may bypass access control)
