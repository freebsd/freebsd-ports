diff -udr ../Cryptix-1.16.ORIG/Crypt-DES/DES.xs ./Crypt-DES/DES.xs
--- ../Cryptix-1.16.ORIG/Crypt-DES/DES.xs	Wed Aug  6 15:45:45 1997
+++ ./Crypt-DES/DES.xs	Fri Aug 10 16:23:39 2001
@@ -48,7 +48,7 @@
 		if (ks_len != sizeof(des_ks))
 			croak("Invalid key schedule");
 
-		if (output == &sv_undef)
+		if (output == &PL_sv_undef)
 			output = sv_newmortal();
 		output_len = 8;
 
