--- GOST.xs.orig	2001-05-13 14:11:35 UTC
+++ GOST.xs
@@ -54,9 +54,11 @@ gost_crypt(self, input, output, decrypt)
             output = sv_newmortal();
         outlen = 8;
 
-        if (SvREADONLY(output) || !SvUPGRADE(output, SVt_PV))
+        if (SvREADONLY(output))
             croak("cannot use output as lvalue");
 
+        SvUPGRADE(output, SVt_PV);
+
         gost_crypt(self,
                    (unsigned char *)input,
                    (unsigned char *)SvGROW(output, outlen),
