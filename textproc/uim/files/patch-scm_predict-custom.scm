--- scm/predict-custom.scm.orig	2025-02-23 08:00:09 UTC
+++ scm/predict-custom.scm
@@ -110,7 +110,7 @@
                      (N_ "Look-SKK prediction")
                      (N_ "long description will be here."))
 
-(define-custom 'predict-custom-look-skk-jisyo "/usr/share/skk/SKK-JISYO.L"
+(define-custom 'predict-custom-look-skk-jisyo "%PREFIX%/share/skk/SKK-JISYO.L"
                '(predict predict-look-skk)
                '(pathname regular-file)
                (N_ "Sorted SKK-JISYO dictionary file")
