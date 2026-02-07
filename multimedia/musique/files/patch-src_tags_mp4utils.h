Fix build with Taglib 2.x

Obtained from:
https://github.com/flaviotordini/musique/commit/7277d40defe9cde40f947a81d624195ddf683f44

--- src/tags/mp4utils.h.orig	2023-06-24 18:44:28 UTC
+++ src/tags/mp4utils.h
@@ -9,7 +9,7 @@ void load(TagLib::MP4::Tag *tag, Tags *tags) {
 namespace Mp4Utils {
 
 void load(TagLib::MP4::Tag *tag, Tags *tags) {
-    const TagLib::MP4::ItemListMap &map = tag->itemListMap();
+    const TagLib::MP4::ItemMap &map = tag->itemMap();
 
     if (map.contains("trkn")) {
         TagLib::MP4::Item::IntPair intPair = map["trkn"].toIntPair();
@@ -31,7 +31,7 @@ void load(TagLib::MP4::Tag *tag, Tags *tags) {
         tags->setComposerSort(v);
     }
 
-    TagLib::MP4::ItemListMap::ConstIterator it = map.find("aART");
+    TagLib::MP4::ItemMap::ConstIterator it = map.find("aART");
     if (it != map.end()) {
         TagLib::StringList sl = it->second.toStringList();
         if (!sl.isEmpty())
