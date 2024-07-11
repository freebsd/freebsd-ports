Fix build with Taglib 2.x.

Deprecated member function MP4::Tag::itemListMap() was removed.

https://github.com/clangen/musikcube/issues/670

--- src/plugins/taglib_plugin/TaglibMetadataReader.cpp.orig	2023-09-11 02:03:12 UTC
+++ src/plugins/taglib_plugin/TaglibMetadataReader.cpp
@@ -320,7 +320,7 @@ bool TaglibMetadataReader::ReadGeneric(
             if (!handled) {
                 const auto mp4File = dynamic_cast<TagLib::MP4::File*>(file.file());
                 if (mp4File && mp4File->hasMP4Tag()) {
-                    auto mp4TagMap = static_cast<TagLib::MP4::Tag*>(tag)->itemListMap();
+                    auto mp4TagMap = static_cast<TagLib::MP4::Tag*>(tag)->itemMap();
                     this->ExtractValueForKey(mp4TagMap, "aART", "album_artist", target);
                     this->ExtractValueForKey(mp4TagMap, "disk", "disc", target);
                     this->ExtractReplayGain(mp4TagMap, target);
