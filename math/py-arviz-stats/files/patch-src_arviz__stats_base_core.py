--- src/arviz_stats/base/core.py.orig	2026-04-17 15:52:28 UTC
+++ src/arviz_stats/base/core.py
@@ -118,10 +118,13 @@ class _CoreBase:
            "Sample quantiles in statistical packages,"
            The American Statistician, 50(4), pp. 361-365, 1996
         """
+        _kwargs = {"axis": axis, "method": method}
+        if weights is not None:
+            _kwargs["weights"] = weights
         if skipna:
-            result = np.nanquantile(ary, quantile, axis=axis, method=method, weights=weights)
+            result = np.nanquantile(ary, quantile, **_kwargs)
         else:
-            result = np.quantile(ary, quantile, axis=axis, method=method, weights=weights)
+            result = np.quantile(ary, quantile, **_kwargs)
         if np.ndim(quantile) == 0:
             return result
         return np.moveaxis(result, 0, -1)
