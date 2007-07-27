
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
@@ -1564,6 +1564,12 @@
 			if (!havewhen)
 				time(&now);
 			diff = c[x]->whentohangup - now;
+			if (diff < 1) {
+				/* Should already be hungup */
+				c[x]->_softhangup |= AST_SOFTHANGUP_TIMEOUT;
+				ast_mutex_unlock(&c[x]->lock);
+				return c[x];
+			}
 			if (!havewhen || (diff < whentohangup)) {
 				havewhen++;
 				whentohangup = diff;
