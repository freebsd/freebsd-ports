--- pyonlinedesktop/widget.py~	2008-04-23 23:06:43.000000000 +0530
+++ pyonlinedesktop/widget.py	2008-05-28 21:29:41.000000000 +0530
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!/usr/bin/env python
 
 import os,sys,re,urllib,urllib2,logging,webbrowser,tempfile,shutil
 import cookielib,urlparse
@@ -188,4 +188,4 @@
             oldv = getattr(self, k)
             newv = self.__substitute_locale_msgs(oldv, msgs)
             setattr(self, k, newv)
-        
\ No newline at end of file
+        
