--- ext/xml/extconf.rb.orig	2006-10-20 13:37:49.000000000 +0200
+++ ext/xml/extconf.rb	2007-12-21 21:01:31.000000000 +0100
@@ -92,7 +92,7 @@
   $CFLAGS << ' -Wall'
 end
 
-$CFLAGS << ' ' << $INCFLAGS
+$CFLAGS << ' ' << $INCFLAGS << ' ' << "-I /usr/local/include -L /usr/local/lib"
 $INSTALLFILES = [["libxml.rb", "$(RUBYLIBDIR)", "../xml"]]
 
 create_header()
