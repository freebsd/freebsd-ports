-- Support the PuLP 4 API: variables are created via LpProblem.add_variable()
-- and PULP_CBC_CMD is replaced by COIN_CMD. Without this
-- balance_stoichiometry() fails with the PuLP version in the ports tree.
-- upstreamed: https://github.com/bjodah/chempy/issues/248

--- chempy/chemistry.py.orig	2026-10-18 17:12:15 UTC
+++ chempy/chemistry.py
@@ -1307,16 +1307,26 @@ def _solve_balancing_ilp_pulp(A):
 def _solve_balancing_ilp_pulp(A):
     import pulp
 
-    x = [
-        pulp.LpVariable("x%d" % i, lowBound=1, cat="Integer") for i in range(A.shape[1])
-    ]
     prob = pulp.LpProblem("chempy_balancing_problem", pulp.LpMinimize)
+    if hasattr(prob, "add_variable"):
+        x = [
+            prob.add_variable("x%d" % i, lowBound=1, cat="Integer")
+            for i in range(A.shape[1])
+        ]
+    else:
+        x = [
+            pulp.LpVariable("x%d" % i, lowBound=1, cat="Integer")
+            for i in range(A.shape[1])
+        ]
     prob += reduce(add, x)
     for expr in [
         pulp.lpSum([x[i] * e for i, e in enumerate(row)]) for row in A.tolist()
     ]:
         prob += expr == 0
-    prob.solve(pulp.PULP_CBC_CMD(msg=False))
+    if hasattr(pulp, "PULP_CBC_CMD"):
+        prob.solve(pulp.PULP_CBC_CMD(msg=False))
+    else:
+        prob.solve(pulp.COIN_CMD(msg=False))
     return [pulp.value(_) for _ in x]
 
 
