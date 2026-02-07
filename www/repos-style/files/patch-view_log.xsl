--- view/log.xsl.orig	2016-06-20 16:09:43 UTC
+++ view/log.xsl
@@ -25,7 +25,7 @@ limitations under the License.
 	
 	<!-- === repos style configuration === -->
 	<!-- static: absolute url to style application -->
-	<xsl:param name="static">/repos-web/</xsl:param>
+	<xsl:param name="static">/repos-style/</xsl:param>
 	<!-- cssUrl: absolute url to css folder -->
 	<xsl:param name="cssUrl"><xsl:value-of select="$static"/>style/</xsl:param>
 	<!-- log viewer does not know the repository URL -->
