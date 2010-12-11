--- setup.py	2004-11-06 11:31:49.000000000 -0200
+++ /tmp/setup.py	2010-11-07 11:45:39.000000000 -0200
@@ -35,7 +35,7 @@
       download_url="http://sourceforge.net/projects/stdiff/",
       packages=["spot"],
       scripts=["scripts/stdiff.py", "scripts/stdiff_install_db.py"],
-      data_files=[("/etc", ["stdiff.conf.sample"])],
+      data_files=[("/usr/local/etc", ["stdiff.conf.sample"])],
       classifiers=["Development status :: 0.2.1",
                    "Environment :: Console (Text Based)",
                    "Intended Audience :: System Administrators",
