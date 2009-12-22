--- src/mlib/stream.h.orig	2009-08-24 15:11:47.000000000 +0700
+++ src/mlib/stream.h	2009-08-24 15:12:03.000000000 +0700
@@ -186,6 +186,7 @@
                         //   write(fd, "some text", 9);
                         //   ..
                         // Причины использования класса io::fd_proxy см. в его описании
+#undef	fileno
            opaque_file  fileno() 
                         { return opaque_file(this->file()); }
 
