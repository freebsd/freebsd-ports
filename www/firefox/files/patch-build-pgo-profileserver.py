--- build/pgo/profileserver.py.orig	2017-09-15 04:15:39 UTC
+++ build/pgo/profileserver.py
@@ -87,7 +87,7 @@ if __name__ == '__main__':
             env["MOZ_JAR_LOG_FILE"] = os.path.abspath(jarlog)
             print "jarlog: %s" % env["MOZ_JAR_LOG_FILE"]
 
-        cmdargs = ["http://localhost:%d/index.html" % PORT]
+        cmdargs = ["http://127.0.0.1:%d/index.html" % PORT]
         runner = FirefoxRunner(profile=profile,
                                binary=build.get_binary_path(
                                    where="staged-package"),
