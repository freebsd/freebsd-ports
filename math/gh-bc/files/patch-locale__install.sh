--- locale_install.sh.orig	2019-05-29 01:32:06 UTC
+++ locale_install.sh
@@ -114,6 +114,7 @@ for file in $locales_dir/*.msg; do
 		continue
 	fi
 
+	echo gencatfile "$loc" "$file"
 	gencatfile "$loc" "$file"
 
 done
@@ -143,7 +144,8 @@ for file in $locales_dir/*.msg; do
 			gencatfile "$destdir/$linksrc" "$linkdir/$link"
 		fi
 
-		ln -s "$linksrc" "$loc"
+		echo ln "$linksrc" "$loc"
+		ln "$linksrc" "$loc"
 	fi
 
 done
