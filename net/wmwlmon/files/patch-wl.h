--- wl.h.orig	2006-05-04 18:44:47 UTC
+++ wl.h
@@ -16,7 +16,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#ifndef __OpenBSD__ 
+#ifndef IFM_TYPE_MATCH
 #define IFM_TYPE_MATCH(dt, t) (IFM_TYPE((dt)) == 0 || \
     IFM_TYPE((dt)) == IFM_TYPE((t)))
 #endif
