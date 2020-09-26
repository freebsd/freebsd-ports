--- libdnf/hy-util.cpp.orig	2020-09-20 22:48:40 UTC
+++ libdnf/hy-util.cpp
@@ -111,10 +111,12 @@ hy_detect_arch(char **arch)
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
