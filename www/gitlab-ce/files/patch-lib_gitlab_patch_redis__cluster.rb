--- lib/gitlab/patch/redis_cluster.rb.orig	2023-07-06 07:35:20 UTC
+++ lib/gitlab/patch/redis_cluster.rb
@@ -4,7 +4,7 @@
 # In redis v5.0.x, cross-slot pipelining is implemented via redis-cluster-client.
 # This patch should be removed since there is no need for it.
 # Gitlab::Redis::CrossSlot and its usage should be removed as well.
-if Gem::Version.new(Redis::VERSION) != Gem::Version.new('4.8.0')
+if Gem::Version.new(Redis::VERSION) != Gem::Version.new('4.8.1')
   raise 'New version of redis detected, please remove or update this patch'
 end
 
