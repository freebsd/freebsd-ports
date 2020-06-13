Fix CLI usability, see also https://github.com/pdfminer/pdfminer.six/issues/405

Obtained from:

https://github.com/pdfminer/pdfminer.six/pull/421/commits/0c2f44b6de064d9a3cea99bde5b8e9c6a525a69c

--- tools/pdf2txt.py.orig	2019-11-10 11:59:55 UTC
+++ tools/pdf2txt.py
@@ -1,3 +1,5 @@
+#!/usr/bin/env python
+
 """A command line tool for extracting text and images from PDF and output it to plain text, html, xml or tags."""
 import argparse
 import logging
