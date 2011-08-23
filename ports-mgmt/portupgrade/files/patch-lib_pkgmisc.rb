diff --git a/lib/pkgmisc.rb b/lib/pkgmisc.rb
index 225408a..83ea9da 100644
--- lib/pkgmisc.rb
+++ lib/pkgmisc.rb
@@ -94,14 +94,6 @@ def shelljoin(*args)
   }.join(' ')
 end
 
-class File
-  if not File.respond_to?('realpath') then
-    def File.realpath(path)
-      return File.expand_path(path)
-    end
-  end
-end
-
 def init_tmpdir
   if ! $tmpdir.nil? && $tmpdir != "" then
     return
