--- src/binwalk/core/magic.py.orig	2021-09-10 19:46:40.000000000 +0200
+++ src/binwalk/core/magic.py	2026-08-02 21:33:59.983203000 +0200
@@ -428,7 +428,7 @@
         # Regex rule to find format strings
         self.fmtstr = re.compile("%[^%]")
         # Regex rule to find periods (see self._do_math)
-        self.period = re.compile("\.")
+        self.period = re.compile(r"\.")
 
     def reset(self):
         self.display_once = set()
