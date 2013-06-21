--- ./setup.py.orig	2013-03-01 06:30:47.000000000 +1100
+++ ./setup.py	2013-06-21 22:07:23.588789531 +1000
@@ -47,7 +47,7 @@
     REQUIREMENTS.append("argparse")
 
 TEST_REQUIREMENTS = list(REQUIREMENTS)
-TEST_REQUIREMENTS.extend(["mock", "nose", "coverage", "tox"])
+TEST_REQUIREMENTS.extend(["mock", "nose"])
 
 try:
     long_description = open("README.rst").read() + "\n\n" + open("HISTORY.rst").read()
@@ -80,5 +80,8 @@
           "Programming Language :: Python :: 2.7",
           "Topic :: Communications",
       ],
+      zip_safe=False,
+      test_suite = 'nose.collector',
       install_requires=REQUIREMENTS,
-      tests_require=TEST_REQUIREMENTS)
+      tests_require=TEST_REQUIREMENTS),
+
