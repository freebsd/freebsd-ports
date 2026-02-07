--- versions/html4_0.pl.orig	2018-03-28 15:49:41 UTC
+++ versions/html4_0.pl
@@ -955,7 +955,7 @@ sub process_tabular {
 
     if ($color_env) {
 	local($color_test) = join(',',@$open_tags_R);
-	if ($color_test =~ /(color{[^}]*})/g ) {
+	if ($color_test =~ /(color\{[^}]*})/g ) {
 	    $color_env = $1;
 	}
     }
