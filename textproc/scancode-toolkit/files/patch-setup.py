--- setup.py.orig	2019-02-15 14:34:52 UTC
+++ setup.py
@@ -125,25 +125,21 @@ setup(
         # cluecode
         # Some nltk version ranges are buggy
         'nltk >= 3.2, < 4.0',
-        'publicsuffix2',
-        'py2-ipaddress >= 2.0, <3.5',
-        'url >= 0.1.4, < 0.1.6',
-        'fingerprints == 0.5.4',
+        'url >= 0.1.4',
+        'fingerprints >= 0.5.4',
 
         # extractcode
         'patch >= 1.15, < 1.20 ',
         # to work around bug http://bugs.python.org/issue19839
         # on multistream bzip2 files: this can removed in Python 3.
         'bz2file >= 0.98',
-        'extractcode-libarchive',
-        'extractcode-7z',
 
         # commoncode
         'backports.os == 0.1.1',
-        'future == 0.16.0',
+        'future >= 0.16.0',
         'text-unidecode >= 1.0, < 2.0',
         # required by saneyaml
-        'PyYAML >= 3.11, <=3.13',
+        'PyYAML >= 3.11',
         'saneyaml',
 
         # licensedcode
@@ -151,7 +147,7 @@ setup(
         'intbitset >= 2.3.0,  < 3.0',
         'boolean.py >= 3.5,  < 4.0',
         'license_expression >= 0.99,  < 1.0',
-        'pyahocorasick >= 1.1, < 1.2',
+        'pyahocorasick >= 1.1',
 
         # multiple
         'lxml >= 4.0.0, < 5.0.0',
@@ -167,8 +163,7 @@ setup(
         'binaryornot >= 0.4.0',
         'chardet >= 3.0.0, <4.0.0',
         # note that we use a short version range because we use a simpler lexer list
-        'pygments >= 2.2.0, <2.3',
-        'typecode-libmagic',
+        'pygments >= 2.2.0',
 
         # packagedcode
         'pefile >= 2018.8.8',
@@ -182,9 +177,8 @@ setup(
         'click >= 6.0.0, < 7.0.0',
         'colorama >= 0.3.9',
         'pluggy >= 0.4.0, < 1.0',
-        'attrs >=17.4, < 19.0',
-        'cattrs',
-        'typing >=3.6, < 3.7',
+        'attrs >=17.4',
+        'typing >=3.6',
 
         # scancode outputs
         'jinja2 >= 2.7.0, < 3.0.0',
