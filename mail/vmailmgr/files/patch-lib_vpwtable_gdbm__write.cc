--- lib/vpwtable/gdbm_write.cc.orig	2002-11-20 15:54:44 UTC
+++ lib/vpwtable/gdbm_write.cc
@@ -18,12 +18,13 @@
 #include <errno.h>
 #include "vpwtable.h"
 #include <gdbm.h>
+#include <unistd.h>
 
 class gdbm_vpwtable_writer : public vpwtable_writer
 {
 private:
-  const mystring& tmpname;
-  const mystring& destname;
+  const mystring tmpname;
+  const mystring destname;
   GDBM_FILE out;
   bool opened;
 public:
@@ -59,10 +60,10 @@ bool gdbm_vpwtable_writer::operator!() const
 
 bool gdbm_vpwtable_writer::put(const vpwentry& vpw)
 {
-  mystring name = vpw->name.lower();
-  datum key = { (char*)name.c_str(), name.length() };
-  mystring binary = vpw->to_record();
-  datum data = { (char*)binary.c_str(), binary.length() };
+  mystring name = vpw.name.lower();
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
+  mystring binary = vpw.to_record();
+  datum data = { (char*)binary.c_str(), static_cast<int>(binary.length()) };
   return gdbm_store(out, key, data, GDBM_INSERT) == 0;
 }
 
