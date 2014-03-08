--- ./setup.py.orig	2013-12-03 05:34:39.000000000 +1100
+++ ./setup.py	2014-03-08 14:28:44.204623431 +1100
@@ -47,7 +47,7 @@
     REQUIREMENTS.append("argparse")
 
 TEST_REQUIREMENTS = list(REQUIREMENTS)
-TEST_REQUIREMENTS.extend(["mock", "nose", "coverage", "tox"])
+TEST_REQUIREMENTS.extend(["mock", "nose"])
 
 try:
     long_description = open("README.rst").read() + "\n\n" + open("HISTORY.rst").read()
@@ -80,5 +80,6 @@
           "Programming Language :: Python :: 2.7",
           "Topic :: Communications",
       ],
+      test_suite = 'nose.collector',
       install_requires=REQUIREMENTS,
       tests_require=TEST_REQUIREMENTS)
