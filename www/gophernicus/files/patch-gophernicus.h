--- gophernicus.h.orig	2019-07-23 01:52:07 UTC
+++ gophernicus.h
@@ -55,7 +55,7 @@
 #define HAVE_SHMEM		/* Shared memory support */
 #define HAVE_UNAME		/* uname() */
 #define HAVE_POPEN		/* popen() */
-#undef  HAVE_STRLCPY		/* strlcpy() from OpenBSD */
+#define HAVE_STRLCPY		/* strlcpy() from OpenBSD */
 #undef  HAVE_SENDFILE		/* sendfile() in Linux & others */
 /* #undef  HAVE_LIBWRAP		   autodetected, don't enable here */
 
