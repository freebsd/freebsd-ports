diff -ubwr ./com32/libutil/sha512crypt.c ../../work/syslinux-3.72/com32/libutil/sha512crypt.c
--- ./com32/libutil/sha512crypt.c	2008-09-26 01:46:02.000000000 +0200
+++ ../../work/syslinux-3.72/com32/libutil/sha512crypt.c	2008-11-25 11:32:22.000000000 +0100
@@ -1,8 +1,8 @@
 /* SHA512-based Unix crypt implementation.
    Released into the Public Domain by Ulrich Drepper <drepper@redhat.com>.  */
 
-#include <alloca.h>
-#include <endian.h>
+#include <stdlib.h>
+#include <machine/endian.h>
 #include <errno.h>
 #include <limits.h>
 #include <stdbool.h>
