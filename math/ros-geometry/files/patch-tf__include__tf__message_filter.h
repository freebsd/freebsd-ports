--- tf/include/tf/message_filter.h.orig	2011-05-27 19:54:24.000000000 +0200
+++ tf/include/tf/message_filter.h	2011-07-26 23:10:48.000000000 +0200
@@ -398,7 +398,7 @@
 
       ++successful_transform_count_;
 
-      signalMessage(evt);
+      this->signalMessage(evt);
     }
     else
     {
