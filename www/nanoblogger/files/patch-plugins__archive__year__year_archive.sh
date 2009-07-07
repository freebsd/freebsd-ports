--- ./plugins/archive/year/year_archive.sh.orig	2008-07-15 20:11:53.000000000 +0200
+++ ./plugins/archive/year/year_archive.sh	2009-06-22 09:33:11.000000000 +0200
@@ -50,7 +50,7 @@
 		set_baseurl "../../"
 
 		ARCHENTRY_LIST=${DB_RESULTS[*]}
-		NB_ArchiveEntryLinks=$(
+		NB_ArchiveEntryLinks=`
 		for entry in ${ARCHENTRY_LIST[*]}; do
 			NB_EntryID=$x_id${entrylink_var//[\/]/-}
 			set_entrylink "$entry"
@@ -66,12 +66,12 @@
 				# Command to help filter order of categories
 				: ${CATLINKS_FILTERCMD:=sort}
 				>"$SCRATCH_FILE".cat_links
-				entry_wcatids=`grep "$entry" "$NB_DATA_DIR/master.$NB_DBTYPE"`
+				entry_wcatids=$(grep "$entry" "$NB_DATA_DIR/master.$NB_DBTYPE")
 				entry_catids=${entry_wcatids##*\>}
 				[ "$entry_wcatids" = "$entry_catids" ] &&
 					entry_catids=
 				for entry_catnum in ${entry_catids//\,/ }; do
-					cat_title=`nb_print "$NB_DATA_DIR"/cat_"$entry_catnum.$NB_DBTYPE" 1`
+					cat_title=$(nb_print "$NB_DATA_DIR"/cat_"$entry_catnum.$NB_DBTYPE" 1)
 					set_catlink cat_"$entry_catnum.$NB_DBTYPE"
 					cat_index="$category_link"
 					# following must fit on single line
@@ -92,7 +92,7 @@
 				- <a href="${ARCHIVES_PATH}$NB_EntryPermalink">$NB_ArchiveEntryTitle</a>
 				$([ ! -z "$NB_EntryCategories" ] && echo "- $NB_EntryCategories")<br />
 			EOF
-		done; month=)
+		done; month=`
 
 		# create links for monthly archives
 		[ -z "$CAL_CMD" ] && CAL_CMD="cal"
