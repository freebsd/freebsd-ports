--- locale_install.sh.orig	2019-11-09 19:04:17 UTC
+++ locale_install.sh
@@ -193,6 +193,7 @@ for file in $locales_dir/*.msg; do
 		continue
 	fi
 
+	echo gencatfile "$loc" "$file"
 	gencatfile "$loc" "$file"
 
 done
@@ -217,14 +218,13 @@ for file in $locales_dir/*.msg; do
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
