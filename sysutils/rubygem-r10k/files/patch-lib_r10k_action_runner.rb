--- lib/r10k/action/runner.rb.orig
+++ lib/r10k/action/runner.rb
@@ -44,7 +44,7 @@
 
         overrides = {}
         overrides[:cachedir] = @opts[:cachedir] unless @opts[:cachedir].nil?
-        overrides[:deploy] = {} if @opts[:'puppet-path'] || @opts[:'generate-types']
+        overrides[:deploy] = {} if !@opts[:'puppet-path'].nil? || !@opts[:'generate-types'].nil?
         overrides[:deploy][:puppet_path] = @opts[:'puppet-path'] unless @opts[:'puppet-path'].nil?
         overrides[:deploy][:generate_types] = @opts[:'generate-types'] unless @opts[:'generate-types'].nil?
 
