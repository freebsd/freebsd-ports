--- ./base/utils.py.orig	2011-05-14 22:26:06.000000000 +0400
+++ ./base/utils.py	2011-07-04 11:57:33.000000000 +0400
@@ -840,8 +840,8 @@
     return True
 
 
-BROWSERS = ['firefox', 'mozilla', 'konqueror', 'galeon', 'skipstone'] # in preferred order
-BROWSER_OPTS = {'firefox': '-new-window', 'mozilla' : '', 'konqueror': '', 'galeon': '-w', 'skipstone': ''}
+BROWSERS = ['xdg-open', 'firefox', 'mozilla', 'konqueror', 'galeon', 'skipstone'] # in preferred order
+BROWSER_OPTS = {'xdg-open': '','firefox': '-new-window', 'mozilla' : '', 'konqueror': '', 'galeon': '-w', 'skipstone': ''}
 
 
 def find_browser():
