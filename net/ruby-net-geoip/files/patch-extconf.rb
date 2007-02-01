--- extconf.rb.orig	Wed Jan  8 07:45:07 2003
+++ extconf.rb	Thu Feb  1 09:20:43 2007
@@ -66,7 +66,7 @@
 EOL
 end
 
-$CFLAGS = '-g -Wall' + $CFLAGS
+$CFLAGS = '-g -Wall ' + $CFLAGS
 
 create_header()
 create_makefile('net/geoip')
