--- src/Main.cpp.orig	Sat Jun  7 19:03:16 2003
+++ src/Main.cpp	Sat Jul 26 14:28:35 2003
@@ -892,18 +892,21 @@
             printf("%s", _("Using x86 3DNow acceleration\n"));
         else if (accel & MPEG2_ACCEL_X86_MMX)
             printf("%s", _("Using x86 MMX acceleration\n"));
+        else
 #endif
 #ifdef ARCH_PPC
         if (accel & MPEG2_ACCEL_PPC_ALTIVEC)
             printf("%s", _("Using PowerPC Altivec acceleration\n"));
+        else
 #endif
 #ifdef ARCH_ALPHA
         if (accel & MPEG2_ACCEL_ALPHA_MVI)
             printf("%s", _("Using Alpha MVI acceleration\n"));
         else if (accel & MPEG2_ACCEL_ALPHA)
             printf("%s", _("Using Alpha acceleration\n"));
+        else
 #endif
-        else if (accel & MPEG2_ACCEL_MLIB)
+        if (accel & MPEG2_ACCEL_MLIB)
             printf("%s", _("Using Mlib acceleration\n"));
         else
             printf("%s", _("Using no special acceleration\n"));
