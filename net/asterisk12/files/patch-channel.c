
$FreeBSD$

--- channel.c.orig
+++ channel.c
@@ -36,7 +36,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 #ifndef ZT_TIMERPING
 #error "You need newer zaptel!  Please svn update zaptel"
