--- rake.d/extensions.rb.orig	2022-03-13 12:54:56 UTC
+++ rake.d/extensions.rb
@@ -62,14 +62,14 @@ class Array
       :windows => %w{linux macos unix         x11},
     }
 
-    reject.each do |os, types|
-      next if !$building_for[os]
+    # Treat other OS (e.g. FreeBSD) the same as Linux wrt. which files to compile
+    os    = $building_for.keys.select { |key| $building_for[key] }.first
+    types = reject[os || :linux]
 
-      re = '(?:' + types.join('|') + ')'
-      re = %r{(?:/|^)#{re}[_.]}
+    re    = '(?:' + types.join('|') + ')'
+    re    = %r{(?:/|^)#{re}[_.]}
 
-      self.reject! { |f| re.match f }
-    end
+    self.reject! { |f| re.match f }
 
     return self
   end
