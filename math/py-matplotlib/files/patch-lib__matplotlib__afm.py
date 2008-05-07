--- lib/matplotlib/afm.py.orig  2008-02-22 14:38:41.000000000 -0500
+++ lib/matplotlib/afm.py      2008-02-22 14:39:40.000000000 -0500
@@ -164,7 +164,7 @@
         num = _to_int(vals[0].split()[1])
         wx = _to_float(vals[1].split()[1])
         name = vals[2].split()[1]
-        bbox = _to_list_of_ints(vals[3][2:])
+        bbox = _to_list_of_floats(vals[3][2:])
         # Workaround: If the character name is 'Euro', give it the corresponding
         # character code, according to WinAnsiEncoding (see PDF Reference).
         if name == 'Euro':
