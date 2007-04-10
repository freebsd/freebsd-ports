--- src/types.h~	Sun Dec 11 21:05:22 2005
+++ src/types.h	Mon Apr  9 16:55:43 2007
@@ -22,20 +22,21 @@
 #include <sys/types.h>
 #include <stdint.h>
 
+#include "port.h"
 
 class filepos_t
   {
 private:
   uint64_t p;
 public:
-  filepos_t(off_t pos, uint32_t offset):p((pos<<24)|(offset&0xffffff))
+  filepos_t(dvbcut_off_t pos, uint32_t offset):p((pos<<24)|(offset&0xffffff))
     {}
   filepos_t(uint64_t pos) : p(pos)
     {}
   ~filepos_t()
     {}
 
-  off_t packetposition() const
+  dvbcut_off_t packetposition() const
     {
     return (p>>24);
     }
@@ -43,7 +44,7 @@
     {
     return uint32_t(p)&0xffffff;
     }
-  off_t fileposition() const
+  dvbcut_off_t fileposition() const
     {
     return packetposition()+packetoffset();
     }
