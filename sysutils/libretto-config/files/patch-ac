diff -urN libapm.h.orig libapm.h
--- libapm.h.orig	Tue May 12 11:05:49 1998
+++ libapm.h	Thu Nov 19 13:02:03 1998
@@ -32,34 +32,44 @@
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
