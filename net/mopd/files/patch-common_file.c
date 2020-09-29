--- common/file.c.orig	1996-08-16 22:39:41 UTC
+++ common/file.c
@@ -44,6 +44,7 @@ static char rcsid[] = "$Id: file.c,v 1.4 1996/08/16 22
 #endif
 #if defined(__FreeBSD__)
 #include <sys/imgact_aout.h>
+#include <sys/endian.h>
 #endif
 #if !defined(MID_VAX)
 #define MID_VAX 140
@@ -345,7 +346,7 @@ getMID(old_mid,new_mid)
 		mid = MID_ARM6;
 		break;
 #endif
-	default:
+	default: break;
 /*###352 [cc] syntax error before `}'%%%*/
 	}
 
@@ -522,7 +523,7 @@ GetAOutFileInfo(fd, load, xfr, a_text, a_text_fill,
 		ex.a_trsize= mopFileGetBX((u_char *)&ex_swap, 24, 4);
 		ex.a_drsize= mopFileGetBX((u_char *)&ex_swap, 28, 4);
 		break;
-	default:
+	default: break;
 /*###525 [cc] syntax error before `}'%%%*/
 	}
 
@@ -575,7 +576,7 @@ GetAOutFileInfo(fd, load, xfr, a_text, a_text_fill,
 		printf("arm32");
 		break;
 #endif
-	default:
+	default: break;
 	}
 	printf(") Magic: ");
 	switch (N_GETMAGIC (ex)) {
