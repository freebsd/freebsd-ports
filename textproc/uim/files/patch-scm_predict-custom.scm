--- scm/predict-custom.scm.orig	2025-05-16 13:44:13 UTC
+++ scm/predict-custom.scm
@@ -110,7 +110,7 @@
                      (N_ "Look-SKK prediction")
                      (N_ "long description will be here."))
 
-(define-custom 'predict-custom-look-skk-jisyo "/usr/share/skk/SKK-JISYO.L"
+(define-custom 'predict-custom-look-skk-jisyo "/usr/local/share/skk/SKK-JISYO.L"
                '(predict predict-look-skk)
                '(pathname regular-file)
                (N_ "Sorted SKK-JISYO dictionary file")
