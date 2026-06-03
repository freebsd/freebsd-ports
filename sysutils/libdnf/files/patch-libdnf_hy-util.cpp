--- libdnf/hy-util.cpp.orig	2025-10-20 13:41:49 UTC
+++ libdnf/hy-util.cpp
@@ -127,10 +127,12 @@ hy_detect_arch(char **arch)
         char *modifier = un.machine + 5;
         while(isdigit(*modifier)) /* keep armv7, armv8, armv9, armv10, armv100, ... */
             modifier++;
+#if !defined(__FreeBSD__)
         if (getauxval(AT_HWCAP) & HWCAP_ARM_VFP)
             *modifier++ = 'h';
         if ((atoi(un.machine+4) == 7) && (getauxval(AT_HWCAP) & HWCAP_ARM_NEON))
             *modifier++ = 'n';
+#endif
         *modifier++ = endian;
         *modifier = 0;
     }
