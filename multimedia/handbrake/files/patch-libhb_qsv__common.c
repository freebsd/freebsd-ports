--- libhb/qsv_common.c.orig	2019-11-09 20:44:32 UTC
+++ libhb/qsv_common.c
@@ -678,7 +678,7 @@ int hb_qsv_info_init()
      */
     mfxSession session;
     mfxVersion version = { .Major = 1, .Minor = 0, };
-#ifdef SYS_LINUX
+#if defined(SYS_LINUX) || defined(SYS_FREEBSD)
     mfxIMPL hw_preference = MFX_IMPL_VIA_ANY;
 #else
     mfxIMPL hw_preference = MFX_IMPL_VIA_D3D11;
@@ -738,7 +738,7 @@ int hb_qsv_info_init()
         }
         else
         {
-#ifndef SYS_LINUX
+#if !defined(SYS_LINUX) && !defined(SYS_FREEBSD)
             // Windows only: After D3D11 we will try D3D9
             if (hw_preference == MFX_IMPL_VIA_D3D11)
                 hw_preference = MFX_IMPL_VIA_D3D9;
