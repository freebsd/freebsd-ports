diff --git a/lib/portsdb.rb b/lib/portsdb.rb
index 3d1d757..95ba620 100644
--- lib/portsdb.rb
+++ lib/portsdb.rb
@@ -185,7 +185,7 @@ class PortsDB
   def make_var(var, dir = ports_dir())
     if var.is_a?(Array)
       vars = var.join(' -V ')
-      `cd #{dir} && make -V #{vars} 2>/dev/null`.map { |val|
+      `cd #{dir} && make -V #{vars} 2>/dev/null`.lines.map { |val|
 	val.strip!
 	if val.empty?
 	  nil
