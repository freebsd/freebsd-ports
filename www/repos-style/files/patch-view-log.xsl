--- view/log.xsl.orig	2009-03-12 22:15:36.000000000 +0100
+++ view/log.xsl	2009-08-21 22:39:20.000000000 +0200
@@ -25,7 +25,7 @@
 	
 	<!-- === repos style configuration === -->
 	<!-- static: absolute url to style application -->
-	<xsl:param name="static">/repos-web/</xsl:param>
+	<xsl:param name="static">/repos-style/</xsl:param>
 	<!-- cssUrl: absolute url to css folder -->
 	<xsl:param name="cssUrl"><xsl:value-of select="$static"/>style/</xsl:param>
 	<!-- log viewer does not know the repository URL -->
