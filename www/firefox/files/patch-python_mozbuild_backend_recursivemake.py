--- python/mozbuild/mozbuild/backend/recursivemake.py.orig	2024-02-06 22:20:32.176365000 +0100
+++ python/mozbuild/mozbuild/backend/recursivemake.py	2024-02-06 22:22:12.303380000 +0100
@@ -549,6 +549,7 @@
             if not reldir:
                 for out in obj.outputs:
                     out = mozpath.join(relobjdir, out)
+                    print('XXX Out: ' + out)
                     assert out not in self._target_per_file
                     self._target_per_file[out] = (relobjdir, tier)
                 for input in obj.inputs:
