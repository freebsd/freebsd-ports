diff -uNr yuvdenoise/motion.c yuvdenoise/motion.c.orig
--- yuvdenoise/motion.c	2002-05-06 04:13:37.000000000 -0400
+++ yuvdenoise/motion.c.orig	2003-07-25 01:52:38.339744992 -0400
@@ -251,6 +251,9 @@
     " movl         %1    , %%eax;          /* load frameadress into eax                          */\n"
     " movl         %2    , %%ebx;          /* load frameadress into ebx                          */\n"
     " movl         %3    , %%ecx;          /* load width       into ecx                          */\n"
+	" shrl         $1    , %%ecx;          /* shift width to scale it in the asm.                */\n"
+	"                                      /* why? we need an lvalue as input... gcc33...        */\n"
+	"                                      /* (carrbc1@wfu.edu)                                  */\n"
     "                                      /*                                                    */\n"
     ".rept 4                    ;          /* Loop for 4 lines                                   */\n"
     " movd        (%%eax), %%mm1;          /* 4 Pixels from filtered frame to mm1                */\n"
@@ -270,7 +273,7 @@
     "                                      /*                                                    */\n"
     " movq         %%mm0 , %0   ;          /* make mm0 available to gcc ...                      */\n"
     :"=m" (a)     
-    :"m" (frm), "m" (ref), "m" (denoiser.frame.w/2)
+    :"m" (frm), "m" (ref), "m" (denoiser.frame.w)
     :"%eax", "%ebx", "%ecx"
     );
 #endif
@@ -295,7 +298,10 @@
     " movl         %1    , %%eax;          /* load frameadress into eax                          */\n"
     " movl         %2    , %%ebx;          /* load frameadress into ebx                          */\n"
     " movl         %3    , %%ecx;          /* load width       into ecx                          */\n"
-    "                           ;          /*                                                    */\n"
+	" shrl         $1    , %%ecx;          /* shift width to scale it in the asm.                */\n"
+	"                                      /* why? we need an lvalue as input... gcc33...        */\n"
+	"                                      /* (carrbc1@wfu.edu)                                  */\n"
+    "                                      /*                                                    */\n"
     " .rept 4                   ;          /*                                                    */\n"
     " movd        (%%eax), %%mm1;          /* 4 Pixels from filtered frame to mm1                */\n"
     " movd        (%%ebx), %%mm2;          /* 4 Pixels from filtered frame to mm2                */\n"
@@ -307,7 +313,7 @@
     "                                      /*                                                    */\n"
     " movq         %%mm0 , %0   ;          /* make mm0 available to gcc ...                      */\n"
     :"=m" (a)     
-    :"m" (frm), "m" (ref), "m" (denoiser.frame.w/2)
+    :"m" (frm), "m" (ref), "m" (denoiser.frame.w)
     :"%eax", "%ebx", "%ecx"
     );
 #endif
@@ -349,6 +355,7 @@
   static uint32_t a;
 #ifdef HAVE_ASM_MMX
   static uint32_t bit_mask[2] = {0x7f7f7f7f,0x7f7f7f7f};
+  static uint32_t* bit_mask_addr = bit_mask;
 
   __asm__ __volatile__
       (
@@ -380,7 +387,7 @@
 	  "                                      /*                                                    */"
 	  " movq         %%mm0 , %0   ;          /* make mm0 available to gcc ...                      */"
 	  :"=m" (a)     
-	  :"m" (frm1),"m" (frm2), "m" (ref), "m" (denoiser.frame.w), "m" (bit_mask)
+	  :"m" (frm1),"m" (frm2), "m" (ref), "m" (denoiser.frame.w), "m" (bit_mask_addr)
 	  :"%eax", "%ebx", "%ecx", "%edx"
 	  );
 #endif
