--- sysdep.h.orig	2008-11-19 20:36:12 UTC
+++ sysdep.h
@@ -34,6 +34,7 @@ int tun_open(char *dev, enum if_mode_enum mode);
 int tun_close(int fd, char *dev);
 int tun_write(int fd, unsigned char *buf, int len);
 int tun_read(int fd, unsigned char *buf, int len);
+void tun_claim(int fd);
 int tun_get_hwaddr(int fd, char *dev, uint8_t *hwaddr);
 
 /***************************************************************************/
@@ -75,17 +76,20 @@ int tun_get_hwaddr(int fd, char *dev, uint8_t *hwaddr)
 /***************************************************************************/
 #if defined(__FreeBSD_kernel__)
 #define HAVE_SA_LEN 1
+#define NEED_IPLEN_FIX 1
 #endif
 
 /***************************************************************************/
 #if defined(__FreeBSD__)
 #define HAVE_SA_LEN 1
+#define NEED_IPLEN_FIX 1
 
 #define HAVE_VASPRINTF 1
 #define HAVE_ASPRINTF  1
 #define HAVE_FGETLN    1
 #define HAVE_UNSETENV  1
 #define HAVE_SETENV    1
+#define HAVE_GETLINE   1
 #endif
 
 /***************************************************************************/
@@ -97,6 +101,7 @@ int tun_get_hwaddr(int fd, char *dev, uint8_t *hwaddr)
 #define HAVE_FGETLN    1
 #define HAVE_UNSETENV  1
 #define HAVE_SETENV    1
+#define HAVE_GETLINE   1
 #endif
 
 /***************************************************************************/
