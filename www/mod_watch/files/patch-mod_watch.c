--- mod_watch.c.orig	Thu Mar 14 12:44:07 2002
+++ mod_watch.c	Mon Oct 28 00:48:48 2002
@@ -41,6 +41,10 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#ifdef INET6
+#error mod_watch is not IPv6-aware.
+#endif
+
 #ifndef SPOOLDIR
 #define SPOOLDIR		"/var/spool/mod_watch/"
 #endif
