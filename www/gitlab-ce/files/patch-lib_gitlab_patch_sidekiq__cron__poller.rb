--- lib/gitlab/patch/sidekiq_cron_poller.rb.orig	2023-05-22 18:44:12 UTC
+++ lib/gitlab/patch/sidekiq_cron_poller.rb
@@ -7,7 +7,7 @@
 require 'sidekiq/version'
 require 'sidekiq/cron/version'
 
-if Gem::Version.new(Sidekiq::VERSION) != Gem::Version.new('6.5.7')
+if Gem::Version.new(Sidekiq::VERSION) != Gem::Version.new('6.5.9')
   raise 'New version of sidekiq detected, please remove or update this patch'
 end
 
