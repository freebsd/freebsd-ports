--- bjc250/src/gdevbjc_.c.orig	Fri Nov  8 06:15:15 2002
+++ bjc250/src/gdevbjc_.c	Fri Nov  8 07:43:31 2002
@@ -54,9 +54,9 @@
 private dev_proc_put_params(gdev_bjc_put_params);
 private dev_proc_get_params(gdev_bjc_get_params);
 const stringParamDescription *
- paramValueToParam(P2(const stringParamDescription *, int));
+ paramValueToParam(const stringParamDescription *, int);
 const stringParamDescription *
- paramStringToParam(P3(const stringParamDescription *, const char *, uint));
+ paramStringToParam(const stringParamDescription *, const char *, uint);
 
 BJL_command BJL_command_set[] = {
     { "@Cleaning=1",            BJC_BJL_CLEANING,      11},
