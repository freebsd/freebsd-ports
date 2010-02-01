--- lib/puppet/provider/cron/crontab.rb.orig	2010-01-11 23:55:13.000000000 +0000
+++ lib/puppet/provider/cron/crontab.rb	2010-01-19 02:49:58.000000000 +0000
@@ -27,13 +27,18 @@
 
     text_line :environment, :match => %r{^\w+=}
 
-    crontab = record_line :crontab, :fields => %w{special minute hour monthday month weekday command},
-        :match => %r{^\s*(?:@(\w+)|(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+))\s+(.+)$},
-        :optional => %w{special minute hour weekday month monthday}, :absent => "*"
+    record_line :freebsd_special, :fields => %w{special command},
+        :match => %r{^@(\w+)\s+(.+)$}, :pre_gen => proc { |record|
+            record[:special] = "@" + record[:special]
+        }
+
+    crontab = record_line :crontab, :fields => %w{minute hour monthday month weekday command},
+        :match => %r{^\s*(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(.+)$},
+        :optional => %w{minute hour weekday month monthday}, :absent => "*"
 
     class << crontab
         def numeric_fields
-            fields - [:command, :special]
+            fields - [:command]
         end
         # Do some post-processing of the parsed record.  Basically just
         # split the numeric fields on ','.
