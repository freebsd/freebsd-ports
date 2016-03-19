--- src/mlib/stream.h.orig	2013-03-07 21:20:45 UTC
+++ src/mlib/stream.h
@@ -186,6 +186,7 @@ class basic_fstream : public basic_iostr
                         //   write(fd, "some text", 9);
                         //   ..
                         // Причины использования класса io::fd_proxy см. в его описании
+#undef	fileno
            opaque_file  fileno() 
                         { return opaque_file(this->file()); }
 
