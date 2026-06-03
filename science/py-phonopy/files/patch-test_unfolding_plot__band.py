--- test/unfolding/plot_band.py.orig	2026-03-06 02:55:00 UTC
+++ test/unfolding/plot_band.py
@@ -5,14 +5,16 @@ import sys
 import matplotlib.pyplot as plt
 import numpy as np
 
-if len(sys.argv) > 1:
-    filename = sys.argv[1]
-else:
-    filename = "bin-unfolding.dat"
+if __name__ == '__main__':
+    if len(sys.argv) > 1:
+        filename = sys.argv[1]
+    else:
+        filename = "bin-unfolding.dat"
 
-x, y, z = np.loadtxt(filename).T
-idx = z.argsort()
-x, y, z = x[idx], y[idx], z[idx]
-sc = plt.scatter(x, y, c=z, s=30, vmin=0, edgecolor=None, cmap="Greys")
-plt.colorbar(sc)
-plt.show()
+    x, y, z = np.loadtxt(filename).T
+    idx = z.argsort()
+    x, y, z = x[idx], y[idx], z[idx]
+    sc = plt.scatter(x, y, c=z, s=30, vmin=0, edgecolor=None, cmap="Greys")
+    plt.colorbar(sc)
+    plt.show()
+
