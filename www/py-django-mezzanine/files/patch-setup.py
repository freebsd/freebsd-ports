--- ./setup.py.orig	2013-04-28 08:33:45.000000000 +1000
+++ ./setup.py	2013-05-08 16:44:15.222197315 +1000
@@ -6,6 +6,8 @@
 
 exclude = ["mezzanine/project_template/dev.db",
            "mezzanine/project_template/local_settings.py"]
+if sys.argv == ["setup.py", "test"]:
+    exclude = []
 exclude = dict([(e, None) for e in exclude])
 for e in exclude:
     if e.endswith(".py"):
@@ -63,6 +65,8 @@
             [console_scripts]
             mezzanine-project=mezzanine.bin.mezzanine_project:create_project
         """,
+        test_suite="runtests.runtests",
+        tests_require=["pyflakes==0.6.1", "pep8==1.4.1"], 
         classifiers=[
             "Development Status :: 4 - Beta",
             "Environment :: Web Environment",
@@ -77,7 +81,8 @@
             "Topic :: Software Development :: Libraries :: "
                                                 "Application Frameworks",
             "Topic :: Software Development :: Libraries :: Python Modules",
-        ])
+        ],
+    )
 
 finally:
     for e in exclude:
