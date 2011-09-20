--- texk/ps2pkm/type1.c.orig	1999-02-06 23:00:18.000000000 +0100
+++ texk/ps2pkm/type1.c	2011-08-18 23:02:17.000000000 +0200
@@ -800,7 +800,7 @@
 static DOUBLE PSFakePop ()
 {
   if (PSFakeTop >= 0) return(PSFakeStack[PSFakeTop--]);
-  else Error0("PSFakePop : Stack empty\n");
+  else { CC; IfTrace0(TRUE, "PSFakePop : Stack empty\n"); errflag = TRUE; return 0; }
   /*NOTREACHED*/
 }
  
