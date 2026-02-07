--- slirpvde/slirp_config.h	Sat Jan 29 15:02:08 2005
+++ slirpvde/slirp_config.h	Sat Jan 29 15:15:18 2005
@@ -61,10 +61,18 @@
 #define HAVE_STDLIB_H
 
 /* Define if you have sys/ioctl.h */
+#ifdef __FreeBSD__
+#define HAVE_SYS_IOCTL_H
+#else
 #undef HAVE_SYS_IOCTL_H
+#endif
 
 /* Define if you have sys/filio.h */
+#ifdef __FreeBSD__
+#define HAVE_SYS_FILIO_H
+#else
 #undef HAVE_SYS_FILIO_H
+#endif
 
 /* Define if you have strerror */
 #define HAVE_STRERROR
@@ -162,7 +170,11 @@
 #define HAVE_MEMMOVE
 
 /* Define if you have <termios.h> */
+#ifdef __FreeBSD__
+#define HAVE_TERMIOS_H
+#else
 #undef HAVE_TERMIOS_H
+#endif
 
 /* Define if you have gethostid */
 #undef HAVE_GETHOSTID
