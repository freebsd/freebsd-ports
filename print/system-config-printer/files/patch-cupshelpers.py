--- cupshelpers.py.orig	2008-03-20 11:49:54.000000000 -0400
+++ cupshelpers.py	2008-03-20 11:51:06.000000000 -0400
@@ -19,7 +19,7 @@
 ## Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 import cups, pprint, os, tempfile, re
-from rhpl.translate import _, N_
+from gettext import gettext as _
 import locale
 
 def debugprint(x):
@@ -456,7 +456,7 @@
 
     # First, a local function.  How to check that something exists
     # in a path:
-    def pathcheck (name, path="/usr/bin:/bin"):
+    def pathcheck (name, path="%%LOCALBASE%%/bin:/usr/bin:/bin:%%PREFIX%%/bin"):
         # Strip out foomatic '%'-style place-holders.
         p = name.find ('%')
         if p != -1:
@@ -551,7 +551,7 @@
                     continue
 
                 exepath = pathcheck (exe,
-                                     "/usr/lib/cups/filter:"
+                                     "%%LOCALBASE%%/libexec/cups/filter:"
                                      "/usr/lib64/cups/filter")
 
     if exe and not exepath:
