# Make pocket actually optional
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220312

--- rainbowstream/rainbow.py.orig	2017-07-03 10:00:26 UTC
+++ rainbowstream/rainbow.py
@@ -20,7 +20,10 @@ from twitter.oauth import OAuth, read_to
 from twitter.oauth_dance import oauth_dance
 from twitter.util import printNicely
 
-from pocket import Pocket
+try:
+    from pocket import Pocket
+except ImportError:
+    pckt = None
 
 from .draw import *
 from .colors import *
