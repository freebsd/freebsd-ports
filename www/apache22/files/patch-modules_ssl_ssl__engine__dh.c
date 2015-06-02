--- modules/ssl/ssl_engine_dh.c.orig	2006-07-12 03:38:44 UTC
+++ modules/ssl/ssl_engine_dh.c
@@ -33,7 +33,7 @@
 /* ----BEGIN GENERATED SECTION-------- */
 
 /*
-** Diffie-Hellman-Parameters: (512 bit)
+** Diffie-Hellman-Parameters: (2048 bit)
 **     prime:
 **         00:9f:db:8b:8a:00:45:44:f0:04:5f:17:37:d0:ba:
 **         2e:0b:27:4c:df:1a:9f:58:82:18:fb:43:53:16:a1:
@@ -41,7 +41,7 @@
 **         0e:3e:30:06:80:a3:03:0c:6e:4c:37:57:d0:8f:70:
 **         e6:aa:87:10:33
 **     generator: 2 (0x2)
-** Diffie-Hellman-Parameters: (1024 bit)
+** Diffie-Hellman-Parameters: (3072 bit)
 **     prime:
 **         00:d6:7d:e4:40:cb:bb:dc:19:36:d6:93:d3:4a:fd:
 **         0a:d5:0c:84:d2:39:a4:5f:52:0b:b8:81:74:cb:98:
@@ -55,7 +55,7 @@
 **     generator: 2 (0x2)
 */
 
-static unsigned char dh512_p[] = {
+static unsigned char dh2048_p[] = {
     0x9F, 0xDB, 0x8B, 0x8A, 0x00, 0x45, 0x44, 0xF0, 0x04, 0x5F, 0x17, 0x37,
     0xD0, 0xBA, 0x2E, 0x0B, 0x27, 0x4C, 0xDF, 0x1A, 0x9F, 0x58, 0x82, 0x18,
     0xFB, 0x43, 0x53, 0x16, 0xA1, 0x6E, 0x37, 0x41, 0x71, 0xFD, 0x19, 0xD8,
@@ -63,17 +63,17 @@ static unsigned char dh512_p[] = {
     0x80, 0xA3, 0x03, 0x0C, 0x6E, 0x4C, 0x37, 0x57, 0xD0, 0x8F, 0x70, 0xE6,
     0xAA, 0x87, 0x10, 0x33,
 };
-static unsigned char dh512_g[] = {
+static unsigned char dh2048_g[] = {
     0x02,
 };
 
-static DH *get_dh512(void)
+static DH *get_dh2048(void)
 {
-    return modssl_dh_configure(dh512_p, sizeof(dh512_p),
-                               dh512_g, sizeof(dh512_g));
+    return modssl_dh_configure(dh2048_p, sizeof(dh2048_p),
+                               dh2048_g, sizeof(dh2048_g));
 }
 
-static unsigned char dh1024_p[] = {
+static unsigned char dh3072_p[] = {
     0xD6, 0x7D, 0xE4, 0x40, 0xCB, 0xBB, 0xDC, 0x19, 0x36, 0xD6, 0x93, 0xD3,
     0x4A, 0xFD, 0x0A, 0xD5, 0x0C, 0x84, 0xD2, 0x39, 0xA4, 0x5F, 0x52, 0x0B,
     0xB8, 0x81, 0x74, 0xCB, 0x98, 0xBC, 0xE9, 0x51, 0x84, 0x9F, 0x91, 0x2E,
@@ -86,14 +86,14 @@ static unsigned char dh1024_p[] = {
     0x88, 0xAE, 0xAA, 0x74, 0x7D, 0xE0, 0xF4, 0xD6, 0xE2, 0xBD, 0x68, 0xB0,
     0xE7, 0x39, 0x3E, 0x0F, 0x24, 0x21, 0x8E, 0xB3,
 };
-static unsigned char dh1024_g[] = {
+static unsigned char dh3072_g[] = {
     0x02,
 };
 
-static DH *get_dh1024(void)
+static DH *get_dh3072(void)
 {
-    return modssl_dh_configure(dh1024_p, sizeof(dh1024_p),
-                               dh1024_g, sizeof(dh1024_g));
+    return modssl_dh_configure(dh3072_p, sizeof(dh3072_p),
+                               dh3072_g, sizeof(dh3072_g));
 }
 
 /* ----END GENERATED SECTION---------- */
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
+system("openssl gendh -out dh2048.pem 2048");
+system("openssl gendh -out dh3072.pem 3072");
 
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
