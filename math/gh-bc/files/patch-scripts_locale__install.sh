--- scripts/locale_install.sh.orig	2023-02-02 08:17:33 UTC
+++ scripts/locale_install.sh
@@ -246,6 +246,7 @@ for file in $locales_dir/*.msg; do
 	# Generate the proper location for the cat file.
 	loc=$(gen_nlspath "$destdir/$nlspath" "$locale" "$main_exec")
 
+	echo gencatfile "$loc" "$file"
 	gencatfile "$loc" "$file"
 
 	printf 'done\n'
@@ -289,8 +290,6 @@ for file in $locales_dir/*.msg; do
 		linkdir=$(dirname "$file")
 		locale=$(basename "$link" .msg)
 		linksrc=$(gen_nlspath "$nlspath" "$locale" "$main_exec")
-		relloc="${loc##$destdir/}"
-		rel=$(relpath "$linksrc" "$relloc")
 
 		# If the target file doesn't exist (because it's for a locale that is
 		# not installed), generate it anyway. It's easier this way.
@@ -300,7 +299,8 @@ for file in $locales_dir/*.msg; do
 
 		# Finally, symlink to the install of the generated cat file that
 		# corresponds to the correct msg file.
-		ln -fs "$rel" "$loc"
+		echo ln "$linksrc" "$loc"
+		ln "$linksrc" "$loc"
 
 		printf 'done\n'
 	fi
