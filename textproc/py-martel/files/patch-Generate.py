From: "Andrew Dalke" <dalke@acm.org>
To: <biopython-dev@biopython.org>
Date: Tue, 16 Jan 2001 18:57:23 -0700

There's a small bug with the debug_level = 2 option
in Martel.  When the debug position is within the
first 8 characters it does not show the match text.

--- Generate.py.orig	Fri Jan 19 14:50:01 2001
+++ Generate.py	Fri Jan 19 14:50:06 2001
@@ -460,7 +460,7 @@
             s = s[:17] + " ... " + s[-17:]
         self.msg = s
     def __call__(self, text, x, end):
-        print "Match %s (x=%d): %s" % (repr(text[x-8:x+8]), x,
+        print "Match %s (x=%d): %s" % (repr(text[max(0, x-8):x+8]), x,
                                             repr(self.msg))
         return x
