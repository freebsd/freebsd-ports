--- sdevel/cctypeinfo.c.orig	2020-07-12 09:44:16 UTC
+++ sdevel/cctypeinfo.c
@@ -6,6 +6,7 @@
  *	modify it under the terms of the WTF Public License version 2 or
  *	(at your option) any later version.
  */
+#include <sys/socket.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -61,9 +62,6 @@ p(intptr_t);
 p(wchar_t);
 p(size_t);
 p(off_t);
-#ifdef HAVE_LOFF_T
-p(loff_t)
-#endif
 p(uint8_t);
 p(uint16_t);
 p(uint32_t);
@@ -98,9 +96,6 @@ int main(void)
 	t(size_t);
 	t(wchar_t);
 	t(off_t);
-#ifdef HAVE_LOFF_T
-	t(loff_t);
-#endif
 	t(uint8_t);
 	t(uint16_t);
 	t(uint32_t);
