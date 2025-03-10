--- scm/predict-look-skk.scm.orig	2025-02-23 08:00:09 UTC
+++ scm/predict-look-skk.scm
@@ -37,7 +37,7 @@
 
 (define-class predict-look-skk predict
   '((limit 10)
-    (jisyo "/usr/share/skk/SKK-JISYO.L")) ;; SKK-JISYO
+    (jisyo "%PREFIX%/share/skk/SKK-JISYO.L")) ;; SKK-JISYO
   '(search))
 
 (class-set-method! predict-look-skk search
