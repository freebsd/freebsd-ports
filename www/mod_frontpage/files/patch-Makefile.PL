--- Makefile.PL	Sun Feb  3 12:20:53 2002
+++ Makefile.PL	Tue Feb  5 18:19:43 2002
@@ -110,7 +110,8 @@
 $_=~ s|\$\(install\)|$install|;
 #$_=~ s|\$\(\)|$|;
 #$_=~ s|\$\(\)|$|;
-$_=~ s|\$\(fpexec_caller\)|$user|;
+$_=~ s|\$\(fpexec_uidcaller\)|$user|;
+$_=~ s|\$\(fpexec_gidcaller\)|$group|;
 $_=~ s|\$\(fpexec_uidmin\)|$uid|;
 $_=~ s|\$\(fpexec_gidmin\)|$gid|;
 $_=~ s|\$\(fpexec_logexec\)|$errorlog|;
