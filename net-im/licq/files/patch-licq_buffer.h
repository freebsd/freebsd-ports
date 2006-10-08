diff -ru licq-1.3.2/include/licq_buffer.h include/licq_buffer.h
--- licq-1.3.2/include/licq_buffer.h	Wed Feb  4 18:00:20 2004
+++ include/licq_buffer.h	Sat Jul 15 16:38:24 2006
@@ -62,7 +62,7 @@
 
    char *Pack(CBuffer *);
    char *Pack(const char *data, int size);
-   char *CBuffer::PackLNTS(const char *);
+   char *PackLNTS(const char *);
    char *PackString(const char *data, unsigned short max = 0);
    char *PackUnsignedShort(unsigned short data);
    char *PackUnsignedLong(unsigned long data);
