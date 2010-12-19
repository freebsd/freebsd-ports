--- ./sci_gateway/c/detectforeground.c.orig	2010-01-31 15:21:14.000000000 +0300
+++ ./sci_gateway/c/detectforeground.c	2010-12-19 12:25:28.752039065 +0300
@@ -93,7 +93,7 @@
        //foreground detection
        else
          {
-           cvUpdateBGStatModel(pSrcImg, bg_model);
+           cvUpdateBGStatModel(pSrcImg, bg_model, -1);
 
            IplImg2Mat(bg_model->foreground, Rhs+1);
          }   
