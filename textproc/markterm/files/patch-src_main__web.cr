--- src/main_web.cr.orig	2026-10-18 22:52:12 UTC
+++ src/main_web.cr
@@ -11,4 +11,19 @@ Markd::Pdf.fetch_remote_images = ENV["MARKPDF_WEB_FETC
 # unless explicitly re-enabled with MARKPDF_WEB_FETCH_IMAGES=1.
 Markd::Pdf.fetch_remote_images = ENV["MARKPDF_WEB_FETCH_IMAGES"]? == "1"
 
-Kemal.run
+# Register fonts from a directory so the playground can use custom faces
+# that are not in the system font paths. --fontdir wins over the
+# MARKPDF_WEB_FONTDIR environment variable; either may list a directory.
+fontdir = ENV["MARKPDF_WEB_FONTDIR"]?
+
+Kemal.config.extra_options do |opts|
+  opts.on("--fontdir DIR", "Directory of .ttf fonts to register (recursive)") do |dir|
+    fontdir = dir
+  end
+end
+
+Kemal.run do
+  if d = fontdir
+    Markd::Pdf.register_font_dir(File.expand_path(d))
+  end
+end
