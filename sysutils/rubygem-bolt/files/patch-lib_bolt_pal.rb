--- lib/bolt/pal.rb.orig	2024-10-31 02:52:31 UTC
+++ lib/bolt/pal.rb
@@ -498,7 +498,7 @@ module Bolt
         require 'puppet-strings'
         require 'puppet-strings/yard'
         PuppetStrings::Yard.setup!
-        YARD::Logger.instance.level = :error
+        YARD::Logger.instance.level = YARD::Logger::Severity::ERROR
         YARD.parse(pp_path)
 
         plan = YARD::Registry.at("puppet_plans::#{plan_name}")
