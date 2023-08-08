--- setup.py.orig	2022-07-21 12:47:45 UTC
+++ setup.py
@@ -0,0 +1,75 @@
+#!/usr/bin/env python3
+# -*- coding: utf-8 -*-
+
+"""A setuptools based setup module.
+See:
+https://packaging.python.org/en/latest/distributing.html
+https://github.com/pypa/sampleproject
+"""
+
+
+# To use a consistent encoding
+from codecs import open
+from os import path
+
+# Always prefer setuptools over distutils
+from setuptools import setup
+
+description = (
+    "A Python package for retrieving, parsing, scanning, and " "sending emails"
+)
+here = path.abspath(path.dirname(__file__))
+
+# Get the long description from the README file
+with open(path.join(here, "README.md"), encoding="utf-8") as f:
+    long_description = f.read()
+
+setup(
+    name="mailsuite",
+    # Versions should comply with PEP440.  For a discussion on single-sourcing
+    # the version across setup.py and the project code, see
+    # https://packaging.python.org/en/latest/single_source_version.html
+    version="1.9.14",
+    description=description,
+    long_description=long_description,
+    # The project's main homepage.
+    url="https://seanthegeek.github.io/mailsuite/",
+    # Author details
+    author="Sean Whalen",
+    author_email="whalenster@gmail.com",
+    # See https://pypi.python.org/pypi?%3Aaction=list_classifiers
+    classifiers=[
+        # How mature is this project? Common values are
+        #   3 - Alpha
+        #   4 - Beta
+        #   5 - Production/Stable
+        "Development Status :: 5 - Production/Stable",
+        # Indicate who your project is intended for
+        "Intended Audience :: Developers",
+        "Intended Audience :: Information Technology",
+        "Operating System :: OS Independent",
+        # Specify the Python versions you support here. In particular, ensure
+        # that you indicate whether you support Python 2, Python 3 or both.
+        "Programming Language :: Python :: 3",
+    ],
+    # What does your project relate to?
+    keywords="email,SMTP,IMAP",
+    # You can just specify the packages manually here if your project is
+    # simple. Or you can use find_packages().
+    packages=["mailsuite"],
+    # Alternatively, if you want to distribute just a my_module.py, uncomment
+    # this:
+    # py_modules=["mailsuite"],
+    # List run-time dependencies here.  These will be installed by pip when
+    # your project is installed. For an analysis of "install_requires" vs pip's
+    # requirements files see:
+    # https://packaging.python.org/en/latest/requirements.html
+    install_requires=[
+        "IMAPClient>=2.1.0",
+        "mail-parser>=3.14.0",
+        "dnspython>=2.0.0",
+        "html2text>=2020.1.16",
+        "publicsuffix2>=2.20190812",
+        "expiringdict==1.2.2",
+    ],
+)
