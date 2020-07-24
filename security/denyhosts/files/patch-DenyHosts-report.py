Obtained from:	https://github.com/denyhosts/denyhosts/commit/d4cdd64d2e3b2c395193a141db8d3c5cbda91f28

--- DenyHosts/report.py.orig	2015-09-16 19:40:15 UTC
+++ DenyHosts/report.py
@@ -1,9 +1,6 @@
 import logging
 import re
 import socket
-# Removing this as it causes runtime errors on Python3.4
-# from types import ListType, TupleType
-import types
 from .util import is_true
 try:
     import syslog
@@ -39,8 +36,8 @@ class Report:
     def add_section(self, message, iterable):
         self.report += "%s:\n\n" % message
         for i in iterable:
-            # if type(i) in (TupleType, ListType):
-            if (type(i) is types.ListType) or (type(i) is types.TupleType):
+            # checks the item type (list or tuple)
+            if isinstance(i, list) or isinstance(i, tuple):
                 extra = ": %d\n" % i[1]
                 i = i[0]
             else:
