* Skip the detection of root rights requirement, the assumption that presence
* of KMS drivers removes the root requirement is only valid for Linux
*
--- hw/xfree86/xorg-wrapper.c.orig	2017-03-15 18:05:25 UTC
+++ hw/xfree86/xorg-wrapper.c
@@ -188,9 +188,6 @@ static int on_console(int fd)
 
 int main(int argc, char *argv[])
 {
-#ifdef WITH_LIBDRM
-    struct drm_mode_card_res res;
-#endif
     char buf[PATH_MAX];
     int i, r, fd;
     int kms_cards = 0;
@@ -227,9 +224,10 @@ int main(int argc, char *argv[])
         }
     }
 
-#ifdef WITH_LIBDRM
+#if defined(WITH_LIBDRM) && defined(__linux__)
     /* Detect if we need root rights, except when overriden by the config */
     if (needs_root_rights == -1) {
+        struct drm_mode_card_res res;
         for (i = 0; i < 16; i++) {
             snprintf(buf, sizeof(buf), DRM_DEV_NAME, DRM_DIR_NAME, i);
             fd = open(buf, O_RDWR);
