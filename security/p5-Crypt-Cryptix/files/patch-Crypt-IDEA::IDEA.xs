diff -udr ../Cryptix-1.16.ORIG/Crypt-IDEA/IDEA.xs ./Crypt-IDEA/IDEA.xs
--- ../Cryptix-1.16.ORIG/Crypt-IDEA/IDEA.xs	Wed Aug  6 15:45:46 1997
+++ ./Crypt-IDEA/IDEA.xs	Fri Aug 10 16:23:50 2001
@@ -63,7 +63,7 @@
 		if (ks_len != sizeof(idea_ks))
 			croak("Invalid key schedule");
 
-		if (output == &sv_undef)
+		if (output == &PL_sv_undef)
 			output = sv_newmortal();
 		output_len = 8;
 
