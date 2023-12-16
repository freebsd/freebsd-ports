From 20b9bc778542b105039471e25e192e51fe9fd61f Mon Sep 17 00:00:00 2001
From: Brian Matherly <brian.matherly@yahoo.com>
Date: Mon, 11 Sep 2023 20:41:59 -0500
Subject: [PATCH] Fix crash dereferencing freed pointer

If the producer is deleted by the application before the avformat_producer
is freed from the cache, then the avformat_producer destructor might
try to access the freed producer.

Hold a reference to the producer until the avformat_producer is also
closed.

--

See also the seemingly FreeBSD-specific issue filed by jhale@:
https://github.com/mltframework/mlt/issues/959
multimedia/shotcut (even more recent Qt6-based versions) reproducibly crashes
when using the undo operation without this patch. multimedia/kdenlive does not
seem to be affected. This port builds with and without this patch, so please
check multimedia/shotcut runtime before removing.

--- src/modules/avformat/producer_avformat.c.orig	2023-11-29 04:03:52 UTC
+++ src/modules/avformat/producer_avformat.c
@@ -220,11 +220,12 @@ mlt_producer producer_avformat_init(mlt_profile profil
 
         // Initialise it
         if (mlt_producer_init(producer, self) == 0) {
-            self->parent = producer;
-
             // Get the properties
             mlt_properties properties = MLT_PRODUCER_PROPERTIES(producer);
 
+            self->parent = producer;
+            mlt_properties_inc_ref(properties);
+
             // Set the resource property (required for all producers)
             mlt_properties_set(properties, "resource", file);
 
@@ -3739,6 +3740,7 @@ static int producer_get_frame(mlt_producer producer, m
     if (!self) {
         self = calloc(1, sizeof(struct producer_avformat_s));
         self->parent = producer;
+        mlt_properties_inc_ref(MLT_PRODUCER_PROPERTIES(producer));
         mlt_service_cache_put(service,
                               "producer_avformat",
                               self,
@@ -3928,6 +3930,7 @@ static void producer_avformat_close(producer_avformat 
         self->vpackets = NULL;
     }
 
+    mlt_properties_dec_ref(MLT_PRODUCER_PROPERTIES(self->parent));
     free(self);
 }
 
