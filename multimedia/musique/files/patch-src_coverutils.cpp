Fix build with Taglib 2.x

Obtained from:
https://github.com/flaviotordini/musique/commit/7277d40defe9cde40f947a81d624195ddf683f44

--- src/coverutils.cpp.orig	2023-11-24 00:47:47 UTC
+++ src/coverutils.cpp
@@ -158,7 +158,7 @@ bool CoverUtils::coverFromMP4(const QString &filename,
     TagLib::MP4::Tag *tag = static_cast<TagLib::MP4::Tag *>(f.tag());
     if (!tag) return false;
 
-    TagLib::MP4::ItemListMap itemsListMap = tag->itemListMap();
+    TagLib::MP4::ItemMap itemsListMap = tag->itemMap();
     TagLib::MP4::Item coverItem = itemsListMap["covr"];
     TagLib::MP4::CoverArtList coverArtList = coverItem.toCoverArtList();
     TagLib::MP4::CoverArt coverArt = coverArtList.front();
