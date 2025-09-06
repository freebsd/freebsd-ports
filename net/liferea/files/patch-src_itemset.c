diff --git src/itemset.c src/itemset.c
index 1b4de79e..9cd12fcc 100644
--- src/itemset.c
+++ src/itemset.c
@@ -234,7 +234,7 @@ itemset_merge_item (itemSetPtr itemSet, GList *items, itemPtr item, gint maxChec
 		itemSet->ids = g_list_prepend (itemSet->ids, GUINT_TO_POINTER (item->id));
 
 		/* step 3: trigger async enrichment */
-		if (node->subscription && node->subscription->html5Extract)
+		if (node && node->subscription && node->subscription->html5Extract)
 			subscription_enrich_item (node->subscription, item);
 
 		debug (DEBUG_UPDATE, "-> added \"%s\" (id=%d) to item set %p...", item_get_title (item), item->id, itemSet);
@@ -258,7 +258,7 @@ itemset_merge_item (itemSetPtr itemSet, GList *items, itemPtr item, gint maxChec
 		}
 
 		/* step 5: Check item for new enclosures to download */
-		if (node->subscription && node->subscription->encAutoDownload) {
+		if (node && node->subscription && node->subscription->encAutoDownload) {
 			GSList *iter = metadata_list_get_values (item->metadata, "enclosure");
 			while (iter) {
 				enclosurePtr enc = enclosure_from_string (iter->data);
