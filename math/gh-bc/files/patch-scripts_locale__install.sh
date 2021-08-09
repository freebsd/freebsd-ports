--- scripts/locale_install.sh.orig	2021-06-28 18:10:45 UTC
+++ scripts/locale_install.sh
@@ -243,6 +243,7 @@ for file in $locales_dir/*.msg; do
 	# Generate the proper location for the cat file.
 	loc=$(gen_nlspath "$destdir/$nlspath" "$locale" "$main_exec")
 
+	echo gencatfile "$loc" "$file"
 	gencatfile "$loc" "$file"
 
 done
@@ -282,8 +283,6 @@ for file in $locales_dir/*.msg; do
 		linkdir=$(dirname "$file")
 		locale=$(basename "$link" .msg)
 		linksrc=$(gen_nlspath "$nlspath" "$locale" "$main_exec")
-		relloc="${loc##$destdir/}"
-		rel=$(relpath "$linksrc" "$relloc")
 
 		# If the target file doesn't exist (because it's for a locale that is
 		# not installed), generate it anyway. It's easier this way.
@@ -293,7 +292,8 @@ for file in $locales_dir/*.msg; do
 
 		# Finally, symlink to the install of the generated cat file that
 		# corresponds to the correct msg file.
-		ln -fs "$rel" "$loc"
+		echo ln "$linksrc" "$loc"
+		ln "$linksrc" "$loc"
 	fi
 
 done
