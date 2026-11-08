Description: Annotate with the public mpmath.mpf; mpmath 1.4 renamed
  mpmath.ctx_mp_python.mpf.
Issue ID: none
Changeset: https://github.com/Mathics3/mathics-core/commit/22080118
TODO: Drop when updating to Mathics 10.0 or later.

--- mathics/core/atoms.py.orig	2025-08-17 02:24:15 UTC
+++ mathics/core/atoms.py
@@ -116,7 +116,7 @@ class Number(Atom, ImmutableValueMixin,
         # Anything that is in a number class is Numeric, so return True.
         return True
 
-    def to_mpmath(self, precision: Optional[int] = None) -> mpmath.ctx_mp_python.mpf:
+    def to_mpmath(self, precision: Optional[int] = None) -> mpmath.mpf:
         """
         Convert self.value to an mpmath number with precision ``precision``
         If ``precision`` is None, use mpmath's default precision.
