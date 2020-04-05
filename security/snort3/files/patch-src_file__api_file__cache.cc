--- src/file_api/file_cache.cc.orig	2020-03-25 14:13:20 UTC
+++ src/file_api/file_cache.cc
@@ -133,7 +133,7 @@ FileContext* FileCache::add(const FileHashKey& hashKey
     struct timeval now;
     packet_gettimeofday(&now);
 
-    struct timeval time_to_add = { timeout, 0 };
+    struct timeval time_to_add = { static_cast<time_t>(timeout), 0 };
     timeradd(&now, &time_to_add, &new_node.cache_expire_time);
 
     new_node.file = new FileContext;
@@ -183,7 +183,7 @@ FileContext* FileCache::find(const FileHashKey& hashKe
     }
 
     struct timeval next_expire_time;
-    struct timeval time_to_add = { timeout, 0 };
+    struct timeval time_to_add = { static_cast<time_t>(timeout), 0 };
     timeradd(&now, &time_to_add, &next_expire_time);
 
     //  Refresh the timer on the cache.
@@ -311,7 +311,7 @@ bool FileCache::apply_verdict(Packet* p, FileContext* 
 
             if (!timerisset(&file_ctx->pending_expire_time))
             {
-                add_time = { lookup_timeout, 0 };
+                add_time = { static_cast<time_t>(lookup_timeout), 0 };
                 timeradd(&now, &add_time, &file_ctx->pending_expire_time);
 
                 if (PacketTracer::is_active())
