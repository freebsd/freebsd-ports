--- view/repos.xsl.orig	2016-06-20 16:09:43 UTC
+++ view/repos.xsl
@@ -31,7 +31,7 @@ limitations under the License.
 
 	<!-- === repos style configuration === -->
 	<!-- static: absolute url to style application -->
-	<xsl:param name="static">/repos-web/</xsl:param>
+	<xsl:param name="static">/repos-style/</xsl:param>
 	<!-- cssUrl: absolute url to css folder -->
 	<xsl:param name="cssUrl"><xsl:value-of select="$static"/>style/</xsl:param>
 	<!-- logUrl: empty -> no log tool, absolute url -> enable 'history' link. Must allow appended query param -->
