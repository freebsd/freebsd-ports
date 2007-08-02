--- IkiWiki/Plugin/graphviz.pm.orig	2007-07-27 11:35:05.000000000 +0200
+++ IkiWiki/Plugin/graphviz.pm	2007-07-27 11:36:02.000000000 +0200
@@ -69,7 +69,12 @@ sub render_graph (\%) { #{{{
 		}
 	}
 
-	return "<img src=\"".urlto($dest, $params{page})."\" />\n";
+	if ($params{preview}) {
+		return "<img src=\"".urlto($dest, "")."\" />\n";
+	}
+	else {
+		return "<img src=\"".urlto($dest, $params{page})."\" />\n";
+	}
 } #}}}
 
 sub graph (@) { #{{{
