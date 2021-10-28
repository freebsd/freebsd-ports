--- lib/gitlab/sidekiq_middleware/monitor.rb.orig	2021-10-27 21:57:04 UTC
+++ lib/gitlab/sidekiq_middleware/monitor.rb
@@ -1,5 +1,7 @@
 # frozen_string_literal: true
 
+require 'sidekiq/job_retry'
+
 module Gitlab
   module SidekiqMiddleware
     class Monitor
