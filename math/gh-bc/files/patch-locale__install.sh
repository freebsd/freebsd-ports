--- locale_install.sh.orig	2020-11-26 16:00:16 UTC
+++ locale_install.sh
@@ -211,6 +211,7 @@ for file in $locales_dir/*.msg; do
 
 	loc=$(gen_nlspath "$destdir/$nlspath" "$locale" "$main_exec")
 
+	echo gencatfile "$loc" "$file"
 	gencatfile "$loc" "$file"
 
 done
@@ -239,14 +240,13 @@ for file in $locales_dir/*.msg; do
 		linkdir=$(dirname "$file")
 		locale=$(basename "$link" .msg)
 		linksrc=$(gen_nlspath "$nlspath" "$locale" "$main_exec")
-		relloc="${loc##$destdir/}"
-		rel=$(relpath "$linksrc" "$relloc")
 
 		if [ ! -f "$destdir/$linksrc" ]; then
 			gencatfile "$destdir/$linksrc" "$linkdir/$link"
 		fi
 
-		ln -fs "$rel" "$loc"
+		echo ln "$linksrc" "$loc"
+		ln "$linksrc" "$loc"
 	fi
 
 done
