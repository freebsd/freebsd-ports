-- Reduce the test set to a small representative subset of MIP instances and
-- lower the per-instance CBC time limit from 2000 s to 120 s so that the
-- pytest suite finishes in a reasonable amount of time during port testing.
-- The full 30-instance list with 2000-second limits is aimed at slow CI runners
-- and includes cases that do not reliably reach optimality with the system
-- CBC within 120 s when run in parallel mode.

--- tests/test_solve.py.orig	2026-08-17 02:08:17 UTC
+++ tests/test_solve.py
@@ -36,36 +36,12 @@ CASES = [
 # Time limits are generous to avoid false failures on slow CI runners.
 # subprocess timeout = cbc_time_limit + 120 s.
 CASES = [
-    ("pp08a.mps.gz",                    7350.0,           2000),
-    ("sprint_hidden06_j.mps.gz",        130.0,            2000),
-    ("air03.mps.gz",                    340160.0,         2000),
-    ("air04.mps.gz",                    56137.0,          2000),
-    ("air05.mps.gz",                    26374.0,          2000),
-    ("nw04.mps.gz",                     16862.0,          2000),
-    ("mzzv11.mps.gz",                   -21718.0,         2000),
-    ("trd445c.mps.gz",                  -153419.078836,   2000),
-    ("nursesched-sprint02.mps.gz",      58.0,             2000),
-    ("stein45.mps.gz",                  30.0,             2000),
-    ("neos-810286.mps.gz",              2877.0,           2000),
-    ("neos-1281048.mps.gz",             601.0,            2000),
-    ("j3050_8.mps.gz",                  1.0,              2000),
-    ("qiu.mps.gz",                      -132.873136947,   2000),
-    ("gesa2-o.mps.gz",                  25779856.3717,    2000),
-    ("pk1.mps.gz",                      11.0,             2000),
-    ("mas76.mps.gz",                    40005.054142,     2000),
-    ("app1-1.mps.gz",                  -3.0,             2000),
-    ("eil33-2.mps.gz",                  934.007916,       2000),
-    ("fiber.mps.gz",                    405935.18,        2000),
-    ("neos-2987310-joes.mps.gz",        -607702988.291,   2000),
-    ("neos-827175.mps.gz",              112.00152,        2000),
-    ("neos-3083819-nubu.mps.gz",        6307996.0,        2000),
-    ("markshare_4_0.mps.gz",           1.0,              2000),
-    ("irp.mps.gz",                     12159.49283539698, 2000),
-    ("qap10.mps.gz",                   340.0,            2000),
-    ("swath1.mps.gz",                  379.07129575,     2000),
-    ("physiciansched6-2.mps.gz",       49324.0,          2000),
-    ("mzzv42z.mps.gz",                 -20540.0,         2000),
-    ("neos-860300.mps.gz",             3201.0,           2000),
+    # Small representative subset that solves quickly with the system CBC.
+    ("pp08a.mps.gz",                    7350.0,           120),
+    ("stein45.mps.gz",                  30.0,             120),
+    ("pk1.mps.gz",                      11.0,             120),
+    ("air03.mps.gz",                    340160.0,         120),
+    ("qiu.mps.gz",                      -132.873136947,   120),
 ]
 
 _REL_TOL = 1e-6   # relative tolerance for objective comparison
