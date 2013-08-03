--- grub-core/gnulib/argp-fmtstream.c.orig
+++ grub-core/gnulib/argp-fmtstream.c
@@ -47,7 +47,11 @@
 #endif
 
 #define INIT_BUF_SIZE 200
+#ifdef __FreeBSD__
+#define PRINTF_SIZE_GUESS 32767
+#else
 #define PRINTF_SIZE_GUESS 150
+#endif
 
 /* Return an argp_fmtstream that outputs to STREAM, and which prefixes lines
    written on it with LMARGIN spaces and limits them to RMARGIN columns
