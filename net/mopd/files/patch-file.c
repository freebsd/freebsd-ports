
$FreeBSD$

--- common/file.c.orig	Sat Aug 17 00:39:41 1996
+++ common/file.c	Mon Aug 23 16:36:03 2004
@@ -44,6 +44,7 @@
 #endif
 #if defined(__FreeBSD__)
 #include <sys/imgact_aout.h>
+#include <sys/endian.h>
 #endif
 #if !defined(MID_VAX)
 #define MID_VAX 140
@@ -345,7 +346,7 @@
 		mid = MID_ARM6;
 		break;
 #endif
-	default:
+	default: break;
 /*###352 [cc] syntax error before `}'%%%*/
 	}
 
@@ -522,7 +523,7 @@
 		ex.a_trsize= mopFileGetBX((u_char *)&ex_swap, 24, 4);
 		ex.a_drsize= mopFileGetBX((u_char *)&ex_swap, 28, 4);
 		break;
-	default:
+	default: break;
 /*###525 [cc] syntax error before `}'%%%*/
 	}
 
@@ -575,7 +576,7 @@
 		printf("arm32");
 		break;
 #endif
-	default:
+	default: break;
 	}
 	printf(") Magic: ");
 	switch (N_GETMAGIC (ex)) {
