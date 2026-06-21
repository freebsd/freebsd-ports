-- Fix struct member ordering in the ethtool_link_settings anonymous struct.
-- The __u32 link_mode_data array must precede the struct ethtool_link_settings
-- member to match the expected memory layout for the ioctl call.
--- third_party/gloo/gloo/common/linux.cc.orig	2022-08-30 11:33:00 UTC
+++ third_party/gloo/gloo/common/linux.cc
@@ -188,8 +188,8 @@ static int getInterfaceSpeedGLinkSettings(int sock, st
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
   constexpr auto link_mode_data_nwords = 3 * 127;
   struct {
-    struct ethtool_link_settings req;
     __u32 link_mode_data[link_mode_data_nwords];
+    struct ethtool_link_settings req;
   } ecmd;
   int rv;
 
