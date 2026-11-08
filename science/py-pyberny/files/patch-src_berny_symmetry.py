-- Pass project_Eckart="both" instead of True to molsym's ProjectionOp.
-- molsym 1.3.0 rejects booleans for project_Eckart and only accepts "both",
-- "translational", "rotational" or None; "both" is the equivalent of True.
-- Not reported upstream.

--- src/berny/symmetry.py.orig	2026-10-25 04:26:29 UTC
+++ src/berny/symmetry.py
@@ -91,7 +91,7 @@ def break_symmetry(
     """
     if symtext is None:
         symtext = _symtext(geom)
-    salcs = ProjectionOp(symtext, CartesianCoordinates(symtext), project_Eckart=True)
+    salcs = ProjectionOp(symtext, CartesianCoordinates(symtext), project_Eckart="both")
     totally_symmetric = symtext.irreps[0].symbol
     nonsym = [salc.coeffs for salc in salcs if salc.irrep.symbol != totally_symmetric]
     if not nonsym:
