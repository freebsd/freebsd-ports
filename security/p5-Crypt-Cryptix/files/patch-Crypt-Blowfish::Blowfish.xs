diff -udr ../Cryptix-1.16.ORIG/Crypt-Blowfish/Blowfish.xs ./Crypt-Blowfish/Blowfish.xs
--- ../Cryptix-1.16.ORIG/Crypt-Blowfish/Blowfish.xs	Wed Aug  6 15:45:43 1997
+++ ./Crypt-Blowfish/Blowfish.xs	Fri Aug 10 16:23:42 2001
@@ -52,7 +52,7 @@
 
 		ks = (char *) SvPV(ST(2), ks_len);
 
-		if (output == &sv_undef)
+		if (output == &PL_sv_undef)
 			output = sv_newmortal();
 		output_len = 8;
 
