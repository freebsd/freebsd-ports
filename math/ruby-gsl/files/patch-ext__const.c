--- ./ext/const.c.orig	2007-12-08 17:45:32.000000000 +0300
+++ ./ext/const.c	2009-11-28 23:21:00.000000000 +0300
@@ -599,7 +599,6 @@
 		  rb_float_new(GSL_CONST_CGSM_ELECTRON_CHARGE));
   rb_define_const(module, "ELECTRON_CHARGE_ESU",
 		  rb_float_new(GSL_CONST_CGSM_ELECTRON_CHARGE*GSL_CONST_CGSM_SPEED_OF_LIGHT));
-  rb_define_const(module, "GAUSS", rb_float_new(GSL_CONST_CGSM_GAUSS));
   rb_define_const(module, "STILB", rb_float_new(GSL_CONST_CGSM_STILB));
   rb_define_const(module, "LUMEN", rb_float_new(GSL_CONST_CGSM_LUMEN));
   rb_define_const(module, "LUX", rb_float_new(GSL_CONST_CGSM_LUX));
