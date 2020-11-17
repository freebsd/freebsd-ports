--- src/providers/ffz/FfzEmotes.cpp.orig	2020-11-16 21:05:47 UTC
+++ src/providers/ffz/FfzEmotes.cpp
@@ -14,7 +14,7 @@ namespace {
     Url getEmoteLink(const QJsonObject &urls, const QString &emoteScale)
     {
         auto emote = urls.value(emoteScale);
-        if (emote.isUndefined())
+        if (emote.isUndefined() || emote.type() == QJsonValue::Null)
         {
             return {""};
         }
