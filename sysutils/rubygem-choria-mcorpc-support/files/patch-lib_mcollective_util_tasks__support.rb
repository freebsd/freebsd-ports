--- lib/mcollective/util/tasks_support.rb.orig	2025-03-09 01:41:22 UTC
+++ lib/mcollective/util/tasks_support.rb
@@ -294,6 +294,7 @@ module MCollective
 
           pid = Process.fork
           if pid.nil?
+            Process.initgroups(run_as, u.gid)
             Process.gid = Process.egid = u.gid
             Process.uid = Process.euid = u.uid
             ENV.delete_if { |name| name !~ /^LC_/ }
