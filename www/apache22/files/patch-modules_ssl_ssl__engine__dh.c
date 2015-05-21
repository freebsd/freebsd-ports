--- modules/ssl/ssl_engine_dh.c.orig	2006-07-12 03:38:44 UTC
+++ modules/ssl/ssl_engine_dh.c
@@ -102,12 +102,12 @@ DH *ssl_dh_GetTmpParam(int nKeyLen)
 {
     DH *dh;
 
-    if (nKeyLen == 512)
-        dh = get_dh512();
-    else if (nKeyLen == 1024)
-        dh = get_dh1024();
+    if (nKeyLen == 2048)
+        dh = get_dh2048();
+    else if (nKeyLen == 3072)
+        dh = get_dh3072();
     else
-        dh = get_dh1024();
+        dh = get_dh3072();
     return dh;
 }
 
@@ -151,7 +151,7 @@ print FP $source;
 close(FP);
 
 #   generate the DH parameters
-print "1. Generate 512 and 1024 bit Diffie-Hellman parameters (p, g)\n";
+print "1. Generate 2048 and 3072 bit Diffie-Hellman parameters (p, g)\n";
 my $rand = '';
 foreach $file (qw(/var/log/messages /var/adm/messages
                   /kernel /vmunix /vmlinuz /etc/hosts /etc/resolv.conf)) {
@@ -161,15 +161,15 @@ foreach $file (qw(/var/log/messages /var
     }
 }
 $rand = "-rand $rand" if ($rand ne '');
-system("openssl gendh $rand -out dh512.pem 512");
-system("openssl gendh $rand -out dh1024.pem 1024");
+system("openssl gendh $rand -out dh2048.pem 2048");
+system("openssl gendh $rand -out dh3072.pem 3072");
 
 #   generate DH param info
 my $dhinfo = '';
-open(FP, "openssl dh -noout -text -in dh512.pem |") || die;
+open(FP, "openssl dh -noout -text -in dh2048.pem |") || die;
 $dhinfo .= $_ while (<FP>);
 close(FP);
-open(FP, "openssl dh -noout -text -in dh1024.pem |") || die;
+open(FP, "openssl dh -noout -text -in dh3072.pem |") || die;
 $dhinfo .= $_ while (<FP>);
 close(FP);
 $dhinfo =~ s|^|** |mg;
@@ -177,10 +177,10 @@ $dhinfo = "\n\/\*\n$dhinfo\*\/\n\n";
 
 #   generate C source from DH params
 my $dhsource = '';
-open(FP, "openssl dh -noout -C -in dh512.pem | indent | expand |") || die;
+open(FP, "openssl dh -noout -C -in dh2048.pem | indent | expand |") || die;
 $dhsource .= $_ while (<FP>);
 close(FP);
-open(FP, "openssl dh -noout -C -in dh1024.pem | indent | expand |") || die;
+open(FP, "openssl dh -noout -C -in dh3072.pem | indent | expand |") || die;
 $dhsource .= $_ while (<FP>);
 close(FP);
 $dhsource =~ s|(DH\s+\*get_dh)(\d+)[^}]*\n}|static $1$2(void)
@@ -203,8 +203,8 @@ print FP $source;
 close(FP);
 
 #   cleanup
-unlink("dh512.pem");
-unlink("dh1024.pem");
+unlink("dh2048.pem");
+unlink("dh3072.pem");
 
 =pod
 */
