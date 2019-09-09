--- setup.py.orig	2019-09-04 12:31:34 UTC
+++ setup.py
@@ -50,7 +50,7 @@ doc_and_conf_files = [
         ]
     ),
     (
-        "share/man/man1",
+        "man/man1",
         [
             "doc/wapiti.1",
             "doc/wapiti-getcookie.1"
@@ -122,6 +122,5 @@ if a script is vulnerable.""",
     },
     # https://buildmedia.readthedocs.org/media/pdf/pytest/3.6.0/pytest.pdf
     tests_require=["pytest", "responses"],
-    setup_requires=["pytest-runner"],
     cmdclass={"test": PyTest}
 )
