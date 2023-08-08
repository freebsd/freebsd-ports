--- src/QGst/message.cpp.orig	2014-07-08 18:38:36 UTC
+++ src/QGst/message.cpp
@@ -157,7 +157,7 @@ QString InfoMessage::debugMessage() const
 
 TagMessagePtr TagMessage::create(const ObjectPtr & source, const TagList & taglist)
 {
-    GstMessage *m = gst_message_new_tag(source, gst_tag_list_copy(taglist));
+    GstMessage *m = gst_message_new_tag(source, gst_tag_list_copy(&taglist));
     return TagMessagePtr::wrap(m, false);
 }
 
