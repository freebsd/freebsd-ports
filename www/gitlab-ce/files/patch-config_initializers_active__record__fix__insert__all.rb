--- config/initializers/active_record_fix_insert_all.rb.orig	2020-05-15 17:18:13 UTC
+++ config/initializers/active_record_fix_insert_all.rb
@@ -7,7 +7,7 @@
 # This is covered by tests in `BulkInsertSafe`
 # that validates handling of different data types
 
-if Rails.gem_version > Gem::Version.new("6.0.2")
+if Rails.gem_version > Gem::Version.new("6.0.3.1")
   raise Gem::DependencyError,
     "Remove patch once the https://github.com/rails/rails/pull/38763 is included"
 end
