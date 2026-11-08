--- src/pdf.cr.orig	2026-10-18 22:52:12 UTC
+++ src/pdf.cr
@@ -241,6 +241,19 @@ module Markd
       end
     end
 
+    # Register every .ttf under a directory (recursive) as a font
+    # candidate. Unusable files are skipped, matching how the shim's own
+    # system-font scan ignores bad metadata. Raises Error when the
+    # directory does not exist.
+    def self.register_font_dir(dir : String) : Nil
+      raise Error.new("font directory '#{dir}' does not exist") unless Dir.exists?(dir)
+      Dir.glob(File.join(dir, "**", "*.ttf")).sort.each do |path|
+        register_font(path)
+      rescue Error
+        # skip files the parser rejects (already non-TTF, corrupt, etc.)
+      end
+    end
+
     # Designate the emoji/symbol fallback font used for emoji codepoints
     # the primary font lacks. When never called, well-known system symbol
     # fonts are probed automatically.
