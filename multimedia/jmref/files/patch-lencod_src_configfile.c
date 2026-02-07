--- lencod/src/configfile.c.orig	2020-09-29 10:22:20 UTC
+++ lencod/src/configfile.c
@@ -70,6 +70,9 @@
 #include "img_io.h"
 #include "ratectl.h"
 
+InputParameters cfgparams;
+char errortext[ET_SIZE];
+
 static void PatchInp                (VideoParameters *p_Vid, InputParameters *p_Inp);
 static int  TestEncoderParams       (Mapping *Map, int bitdepth_qp_scale[3]);
 static int  DisplayEncoderParams    (Mapping *Map);
