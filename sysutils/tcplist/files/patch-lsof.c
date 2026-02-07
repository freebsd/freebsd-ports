--- lsof.c.orig	2014-07-27 08:59:42.000000000 +0000
+++ lsof.c
@@ -27,7 +27,7 @@
 #define LSOFCMD  "lsof -HPsli TCP | awk '{print $3,$NF}' | sort | uniq"
 #else /* !OLDLSOF */
 /* These use the current (as of 3.62W, at least) parameters for lsof */
-#define LSOFCMD  "lsof -nPsli TCP | awk '{print $3,$NF}' | sort | uniq"
+#define LSOFCMD  "lsof -nPls -iTCP | awk '{print $3,$(NF - 1)}' | tail -n+2 | sort | uniq"
 #endif /* !OLDLSOF */
 #endif /* LSOFCMD */
 
