--- view/repos.xsl.orig	2009-03-13 09:34:04.000000000 +0100
+++ view/repos.xsl	2009-08-21 22:42:04.000000000 +0200
@@ -31,7 +31,7 @@
 
 	<!-- === repos style configuration === -->
 	<!-- static: absolute url to style application -->
-	<xsl:param name="static">/repos-web/</xsl:param>
+	<xsl:param name="static">/repos-style/</xsl:param>
 	<!-- cssUrl: absolute url to css folder -->
 	<xsl:param name="cssUrl"><xsl:value-of select="$static"/>style/</xsl:param>
 	<!-- logUrl: empty -> no log tool, absolute url -> enable 'history' link. Must allow appended query param -->
