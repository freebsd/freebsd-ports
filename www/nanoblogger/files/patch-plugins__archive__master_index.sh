--- ./plugins/archive/master_index.sh.orig	2008-05-27 06:37:33.000000000 +0200
+++ ./plugins/archive/master_index.sh	2009-06-22 09:31:59.000000000 +0200
@@ -65,7 +65,7 @@
 	cat_total=${#db_categories[*]}
 	if [ "$cat_total" -gt 0 ]; then
 		# make NB_CategoryLinks placeholder
-		NB_BrowseCategoryLinks=$(
+		NB_BrowseCategoryLinks=`
 		cat <<-EOF
 			<a id="category"></a>
 			<strong>$template_browsecat</strong>
@@ -73,7 +73,7 @@
 				$NB_ArchiveCategoryLinks
 			</div>
 			<br />
-		EOF)
+		EOF`
 	fi
 
 	# make NB_ArchiveLinks placeholder
