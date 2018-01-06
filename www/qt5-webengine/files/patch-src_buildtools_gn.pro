--- src/buildtools/gn.pro
+++ src/buildtools/gn.pro
@@ -20,7 +20,7 @@ build_pass|!debug_and_release {
             src_3rd_party_dir = $$absolute_path("$${getChromiumSrcDir()}/../", "$$QTWEBENGINE_ROOT")
             gn_bootstrap = $$system_path($$absolute_path(chromium/tools/gn/bootstrap/bootstrap.py, $$src_3rd_party_dir))
             gn_args = $$system_quote($$gn_args)
-            gn_configure = $$system_quote($$gn_bootstrap) --shadow --gn-gen-args=$$gn_args $$ninja_path
+            gn_configure = $$system_quote($$gn_bootstrap) --no-clean --no-rebuild --shadow --gn-gen-args=$$gn_args $$ninja_path
             !system("cd $$system_quote($$system_path($$dirname(out))) && $$pythonPathForSystem() $$gn_configure") {
                 error("GN build error!")
             }
