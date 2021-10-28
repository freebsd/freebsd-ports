--- lib/gitlab/sidekiq_logging/structured_logger.rb.orig	2021-10-21 22:00:37 UTC
+++ lib/gitlab/sidekiq_logging/structured_logger.rb
@@ -2,6 +2,8 @@
 
 require 'active_record'
 require 'active_record/log_subscriber'
+require 'sidekiq/job_logger'
+require 'sidekiq/job_retry'
 
 module Gitlab
   module SidekiqLogging
