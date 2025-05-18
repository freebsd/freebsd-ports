--- scm/predict-look-skk.scm.orig	2025-05-16 13:44:13 UTC
+++ scm/predict-look-skk.scm
@@ -37,7 +37,7 @@
 
 (define-class predict-look-skk predict
   '((limit 10)
-    (jisyo "/usr/share/skk/SKK-JISYO.L")) ;; SKK-JISYO
+    (jisyo "/usr/local/share/skk/SKK-JISYO.L")) ;; SKK-JISYO
   '(search))
 
 (class-set-method! predict-look-skk search
