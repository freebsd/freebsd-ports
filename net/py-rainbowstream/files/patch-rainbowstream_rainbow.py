# Make pocket actually optional
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220312

--- rainbowstream/rainbow.py.orig	2018-08-28 02:35:54 UTC
+++ rainbowstream/rainbow.py
@@ -20,7 +20,10 @@ from twitter.oauth import OAuth, read_token_file
 from twitter.oauth_dance import oauth_dance
 from twitter.util import printNicely
 
-from pocket import Pocket
+try:
+    from pocket import Pocket
+except ImportError:
+    pckt = None
 
 from .draw import *
 from .colors import *
