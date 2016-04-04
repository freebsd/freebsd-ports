--- libapm.h.orig	1998-05-12 02:05:49 UTC
+++ libapm.h
@@ -32,34 +32,44 @@ static inline int port_inw( int port )
 #define outb(port, value) port_out(value, port)
 #define outw(port, value) port_outw(value, port)
 
+#ifdef __linux__
 int io_enable(void)
 {
   ioperm(0x70, 1, 1);
   ioperm(0x71, 1, 1);
   return 0;
 }
+#endif
 
+#ifdef __linux__
 int io_disable(void)
 {
   ioperm(0x70, 0, 1);
   ioperm(0x71, 0, 1);
   return 0;
 }
+#endif
 
 int get_cmos(int index)
 {
   int r;
 
+#ifdef __linux__
   io_enable();
+#endif
   outb(0x70, index);
   r = inb(0x71);
+#ifdef __linux__
   io_disable();
+#endif
   return r;
 }
 
 int set_cmos(int index, int value)
 {
+#ifdef __linux__
   io_enable();
+#endif
   outb(0x70, index);
   outb(0x71, value);
   return 0;
