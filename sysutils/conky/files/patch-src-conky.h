--- src/conky.h.orig	Fri Sep  2 21:46:54 2005
+++ src/conky.h	Fri Sep  2 21:47:46 2005
@@ -30,7 +30,7 @@
 #endif
 #endif /* X11 */
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(i386) || defined(__i386__)
 #include <machine/apm_bios.h>
 #endif /* __FreeBSD__ */
 
@@ -360,7 +360,7 @@
 #endif
 
 /* in freebsd.c */
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(i386) || defined(__i386__)
 int apm_getinfo(int fd, apm_info_t aip);
 char *get_apm_adapter(void);
 char *get_apm_battery_life(void);
