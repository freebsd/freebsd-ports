--- lib/portsdb.rb.orig	Tue Aug  2 10:24:50 2005
+++ lib/portsdb.rb	Tue Aug  2 10:25:17 2005
@@ -846,7 +846,7 @@
 
   def all_depends_list(origin, before_args = nil, after_args = nil)
     if !before_args && !after_args && i = port(origin)
-      i.all_depends.map { |n| origin(n) }
+      i.all_depends.map { |n| origin(n) }.compact
     else
       all_depends_list!(origin, before_args, after_args)
     end
