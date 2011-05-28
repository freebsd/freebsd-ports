--- Gen.xs.orig	2002-04-10 13:05:58.000000000 +0200
+++ Gen.xs	2011-05-06 11:32:45.000000000 +0200
@@ -146,7 +146,7 @@
     CV *cv;
     klen = strlen(name);
     (void) hv_fetch(missing, name, klen, TRUE);
-    cv = newXS(name, NULL, file); /* newSUB with no block */
+    cv = newXS(name, Perl_cv_undef, file); /* newSUB with no block */
     sv_setsv((SV*)cv, &PL_sv_no); /* prototype it as "()" */
 }
 
