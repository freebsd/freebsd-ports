--- param.h.orig	2024-06-23 08:32:52 UTC
+++ param.h
@@ -2553,7 +2553,7 @@ USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILI
 
 #endif
 
-#if defined(POWER9) && defined(OS_LINUX)
+#if defined(POWER9) && (defined(OS_LINUX) || defined(OS_FREEBSD))
 
 #define SNUMOPT		16
 #define DNUMOPT		8
