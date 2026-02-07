--- scripts/locale_install.sh.orig	2024-09-24 03:54:03 UTC
+++ scripts/locale_install.sh
@@ -247,6 +247,7 @@ for file in $locales_dir/*.msg; do
 	# Generate the proper location for the cat file.
 	loc=$(gen_nlspath "$destdir/$nlspath" "$locale" "$main_exec")
 
+	echo gencatfile "$loc" "$file"
 	gencatfile "$loc" "$file"
 
 	printf 'done\n'
@@ -290,8 +291,6 @@ for file in $locales_dir/*.msg; do
 		linkdir=$(dirname "$file")
 		locale=$(basename "$link" .msg)
 		linksrc=$(gen_nlspath "$nlspath" "$locale" "$main_exec")
-		relloc="${loc##$destdir/}"
-		rel=$(relpath "$linksrc" "$relloc")
 
 		# If the target file doesn't exist (because it's for a locale that is
 		# not installed), generate it anyway. It's easier this way.
@@ -301,7 +300,8 @@ for file in $locales_dir/*.msg; do
 
 		# Finally, symlink to the install of the generated cat file that
 		# corresponds to the correct msg file.
-		ln -fs "$rel" "$loc"
+		echo ln "$linksrc" "$loc"
+		ln "$linksrc" "$loc"
 
 		printf 'done\n'
 	fi
