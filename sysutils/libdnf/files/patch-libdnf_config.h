--- libdnf/config.h.orig	2021-04-12 15:10:19 UTC
+++ libdnf/config.h
@@ -18,7 +18,7 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <stdint.h>
 #else
 #include <bits/wordsize.h>
