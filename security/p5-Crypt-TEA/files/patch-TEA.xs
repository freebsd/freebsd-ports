--- TEA.xs.orig	2001-05-21 17:32:59 UTC
+++ TEA.xs
@@ -55,9 +55,11 @@ tea_crypt(self, input, output, decrypt)
             output = sv_newmortal();
         outlen = 8;
 
-        if (SvREADONLY(output) || !SvUPGRADE(output, SVt_PV))
+        if (SvREADONLY(output))
             croak("cannot use output as lvalue");
 
+        SvUPGRADE(output, SVt_PV);
+
         tea_crypt(self,
                   (unsigned char *)input,
                   (unsigned char *)SvGROW(output, outlen),
