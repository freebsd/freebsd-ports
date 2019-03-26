--- opaque.c.orig	2019-02-20 00:22:27 UTC
+++ opaque.c
@@ -54,13 +54,17 @@
 #include <assert.h>     //assert
 #include <err.h>        //warnx
 #include <errno.h>      //errno
+#if defined(__amd64__) || defined(__i386__)
 #include <machine/pc/bios.h>
+#endif
 #include <stdbool.h>
 #include <stdio.h>      //printf
 #include <stdlib.h>     //free
 #include <string.h>     //strdup
 #include <unistd.h>     //getpagesize
+#if defined(__amd64__) || defined(__i386__)
 #include <x86/metadata.h>
+#endif
 
 #include <libxo/xo.h>
 #include <sysctlmibinfo.h>
