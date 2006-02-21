--- extconf.rb.orig	Tue Feb 21 00:34:57 2006
+++ extconf.rb	Tue Feb 21 00:35:07 2006
@@ -1,5 +1,5 @@
 require "mkmf"
 #$LDFLAGS = "-lsp"
-$LOCAL_LIBS = "-ltsp -lpthread"
+$LOCAL_LIBS = "-ltspread -lpthread"
 create_makefile("spread")
 
