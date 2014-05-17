--- plugins/videofilters/bgyadif.c.orig
+++ plugins/videofilters/bgyadif.c
@@ -704,7 +704,7 @@
 \
             /* if(p->mode<2) ... */\
             "movq    %[tmp3], %%mm6 \n\t" /* diff */\
-            "cmp       $2, %[mode] \n\t"\
+            "cmpl      $2, %[mode] \n\t"\
             "jge       1f \n\t"\
             LOAD4("(%["prev2"],%[mrefs],2)", %%mm2) /* prev2[x-2*refs] */\
             LOAD4("(%["next2"],%[mrefs],2)", %%mm4) /* next2[x-2*refs] */\
