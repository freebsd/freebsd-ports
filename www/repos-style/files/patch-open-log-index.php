--- open/log/index.php.orig	2009-03-13 11:39:06.000000000 +0100
+++ open/log/index.php	2009-08-21 22:36:25.000000000 +0200
@@ -18,7 +18,7 @@
 // === Print svn log --xml to response ===
 
 // Set the URL to the stylesheet, must be same host or absolute path from root
-$xslt = '/repos-web/view/log.xsl';
+$xslt = '/repos-style/view/log.xsl';
 
 // URL or path to repository, no trailing slash
 // (note that the log viewer may bypass access control)
