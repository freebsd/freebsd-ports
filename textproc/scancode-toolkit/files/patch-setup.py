--- setup.py.orig	2018-10-19 14:31:36 UTC
+++ setup.py
@@ -125,9 +125,7 @@ setup(
         # cluecode
         # Some nltk version ranges are buggy
         'nltk >= 3.2, < 4.0',
-        'publicsuffix2',
-        'py2-ipaddress >= 2.0, <3.5',
-        'url >= 0.1.4, < 0.1.6',
+        'url >= 0.1.4',
         'fingerprints == 0.5.4',
 
         # extractcode
@@ -135,8 +133,6 @@ setup(
         # to work around bug http://bugs.python.org/issue19839
         # on multistream bzip2 files: this can removed in Python 3.
         'bz2file >= 0.98',
-        'extractcode-libarchive',
-        'extractcode-7z',
 
         # commoncode
         'backports.os == 0.1.1',
@@ -166,7 +162,6 @@ setup(
         'chardet >= 3.0.0, <4.0.0',
         # note that we use a short version range because we use a simpler lexer list
         'pygments >= 2.2.0, <2.3',
-        'typecode-libmagic',
 
         # packagedcode
         'pefile >= 2018.8.8',
@@ -180,7 +175,6 @@ setup(
         'colorama >= 0.3.9',
         'pluggy >= 0.4.0, < 1.0',
         'attrs >=17.4, < 19.0',
-        'cattrs',
         'typing >=3.6, < 3.7',
 
         # scancode outputs
