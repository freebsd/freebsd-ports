--- src/if_media.c.orig
+++ src/if_media.c
@@ -95,8 +95,13 @@
      *
      */
 
+#if __FreeBSD__ >= 2 
+    type = IFM_TYPE(ifmr.ifm_active);
+    physical = IFM_SUBTYPE(ifmr.ifm_active);
+#else
     type = ifmr.ifm_active & 0xf0;
     physical = ifmr.ifm_active & 0x0f;
+#endif
 
 #ifdef MEDIADEBUG
     printf("      all: %6d\n", ifmr.ifm_current);
