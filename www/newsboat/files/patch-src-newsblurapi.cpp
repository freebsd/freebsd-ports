--- src/newsblurapi.cpp.orig	2020-03-22 18:54:24 UTC
+++ src/newsblurapi.cpp
@@ -165,7 +165,7 @@ void NewsBlurApi::add_custom_headers(curl_slist** /* c
 bool request_successfull(json_object* payload)
 {
 	json_object* result{};
-	if (json_object_object_get_ex(payload, "result", &result) == FALSE) {
+	if (json_object_object_get_ex(payload, "result", &result) == 0) {
 		return false;
 	} else {
 		return !strcmp("ok", json_object_get_string(result));
@@ -241,7 +241,7 @@ rsspp::Feed NewsBlurApi::fetch_feed(const std::string&
 
 		json_object* stories{};
 		if (json_object_object_get_ex(
-				query_result, "stories", &stories) == FALSE) {
+				query_result, "stories", &stories) == 0) {
 			LOG(Level::ERROR,
 				"NewsBlurApi::fetch_feed: request returned no "
 				"stories");
@@ -270,37 +270,37 @@ rsspp::Feed NewsBlurApi::fetch_feed(const std::string&
 			json_object* node{};
 
 			if (json_object_object_get_ex(
-					item_obj, "story_title", &node) == TRUE) {
+					item_obj, "story_title", &node) == 1) {
 				item.title = json_object_get_string(node);
 			}
 
 			if (json_object_object_get_ex(
-					item_obj, "story_authors", &node) == TRUE) {
+					item_obj, "story_authors", &node) == 1) {
 				item.author = json_object_get_string(node);
 			}
 
 			if (json_object_object_get_ex(item_obj,
 					"story_permalink",
-					&node) == TRUE) {
+					&node) == 1) {
 				item.link = json_object_get_string(node);
 			}
 
 			if (json_object_object_get_ex(
-					item_obj, "story_content", &node) == TRUE) {
+					item_obj, "story_content", &node) == 1) {
 				item.content_encoded =
 					json_object_get_string(node);
 			}
 
 			const char* article_id{};
 			if (json_object_object_get_ex(item_obj, "id", &node) ==
-				TRUE) {
+				1) {
 				article_id = json_object_get_string(node);
 			}
 			item.guid = id + ID_SEPARATOR +
 				(article_id ? article_id : "");
 
 			if (json_object_object_get_ex(
-					item_obj, "read_status", &node) == TRUE) {
+					item_obj, "read_status", &node) == 1) {
 				if (!static_cast<bool>(
 						json_object_get_int(node))) {
 					item.labels.push_back(
@@ -311,7 +311,7 @@ rsspp::Feed NewsBlurApi::fetch_feed(const std::string&
 			}
 
 			if (json_object_object_get_ex(
-					item_obj, "story_date", &node) == TRUE) {
+					item_obj, "story_date", &node) == 1) {
 				const char* pub_date =
 					json_object_get_string(node);
 				item.pubDate_ts = parse_date(pub_date);
