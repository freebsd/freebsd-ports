--- Generate.py.orig	Wed Nov 22 09:26:48 2000
+++ Generate.py	Thu Dec  7 12:27:09 2000
@@ -268,11 +268,11 @@
 
     # Must repeat at least "i" times.
     for i in range(min_count):
-        result.append( (None, TT.SubTable, tuple(tagtable)) )
+        result.append( (">ignore", TT.Table, tuple(tagtable)) )
 
     # Special case for when the max count means "unbounded"
     if max_count == sre_parse.MAXREPEAT:
-        result.append( (None, TT.SubTable, tuple(tagtable),
+        result.append( (">ignore", TT.Table, tuple(tagtable),
                                   +1, 0))
     elif min_count == max_count:
         # Special case when i == j
