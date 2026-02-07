TagLib::AudioProperties::length() is deprecated in Taglib 2.x.

--- src/tags/tagutils.cpp.orig	2023-06-24 18:44:28 UTC
+++ src/tags/tagutils.cpp
@@ -49,7 +49,7 @@ Tags *TagUtils::load(const QString &filename) {
         tags->setComment(TagUtils::qString(tag->comment()));
         TagLib::AudioProperties *audioProperties = fileref.audioProperties();
         if (audioProperties)
-            tags->setDuration(audioProperties->length());
+            tags->setDuration(audioProperties->lengthInSeconds());
     }
 
     /*
