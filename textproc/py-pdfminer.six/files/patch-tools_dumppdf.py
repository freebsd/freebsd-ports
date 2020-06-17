Fix CLI usability, see also https://github.com/pdfminer/pdfminer.six/issues/405

Obtained from:

https://github.com/pdfminer/pdfminer.six/pull/421/commits/0c2f44b6de064d9a3cea99bde5b8e9c6a525a69c

--- tools/dumppdf.py.orig	2020-06-12 21:01:43 UTC
+++ tools/dumppdf.py
@@ -1,3 +1,5 @@
+#!/usr/bin/env python
+
 """Extract pdf structure in XML format"""
 import logging
 import os.path
