--- yum/packages.py.orig
+++ yum/packages.py
@@ -1353,11 +1353,14 @@
            is a pre-requires or a not"""
         # FIXME this should probably be put in rpmUtils.miscutils since 
         # - that's what it is
+        RPMSENSE_PREREQ = (1 << 6)
+        RPMSENSE_SCRIPT_PRE = (1 << 9)
+        RPMSENSE_SCRIPT_POST = (1 << 10)
         if flag is not None:
             # Note: RPMSENSE_PREREQ == 0 since rpm-4.4'ish
-            if flag & (rpm.RPMSENSE_PREREQ |
-                       rpm.RPMSENSE_SCRIPT_PRE |
-                       rpm.RPMSENSE_SCRIPT_POST):
+            if flag & (RPMSENSE_PREREQ |
+                       RPMSENSE_SCRIPT_PRE |
+                       RPMSENSE_SCRIPT_POST):
                 return 1
         return 0
 
-- 
1.6.0.2

