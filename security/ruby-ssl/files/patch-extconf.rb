--- extconf.rb.orig	Tue Jan  2 06:03:16 2001
+++ extconf.rb	Tue Jan  9 19:47:42 2001
@@ -2,7 +2,7 @@
 
 SSLLIB="ssl"
 
-$CFLAGS += "-I/usr/include/openssl "
+dir_config("ssl")
 $LDFLAGS += "-lcrypto "
 
 if have_header("ssl.h")
