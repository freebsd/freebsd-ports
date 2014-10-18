--- tools/jtest/jtest.cc.orig	2014-10-08 13:50:58.000000000 -0400
+++ tools/jtest/jtest.cc	2014-10-08 13:51:12.000000000 -0400
@@ -2689,7 +2689,7 @@
     ink_assert( !ftruncate(fd,numbytes) );
     bytes = (unsigned char *)
       mmap(NULL,numbytes,PROT_READ|PROT_WRITE,
-           MAP_SHARED|MAP_NORESERVE,
+           MAP_SHARED,
            fd, 0);
     if (bytes == (unsigned char*)MAP_FAILED || !bytes)
       panic("unable to map URL Hash file\n");
