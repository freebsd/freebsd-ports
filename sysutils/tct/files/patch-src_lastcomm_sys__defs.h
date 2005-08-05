
$FreeBSD$

--- src/lastcomm/sys_defs.h.orig
+++ src/lastcomm/sys_defs.h
@@ -6,7 +6,7 @@
   * This software is distributed under the IBM Public License.
   */
 #if defined(FREEBSD2) || defined(FREEBSD3)  || defined(FREEBSD4) \
-	|| defined(FREEBSD5) \
+	|| defined(FREEBSD5) || defined(FREEBSD6) || defined(FREEBSD7) \
 	|| defined(BSDI2) || defined(BSDI3) || defined(BSDI4) \
 	|| defined(OPENBSD2) || defined(OPENBSD3)
 #define SUPPORTED
