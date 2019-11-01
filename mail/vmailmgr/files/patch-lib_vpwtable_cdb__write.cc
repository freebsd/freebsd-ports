--- lib/vpwtable/cdb_write.cc.orig	2002-11-20 15:54:44 UTC
+++ lib/vpwtable/cdb_write.cc
@@ -23,8 +23,8 @@
 class cdb_vpwtable_writer : public vpwtable_writer
 {
 private:
-  const mystring& tmpname;
-  const mystring& cdbname;
+  const mystring tmpname;
+  const mystring cdbname;
   cdb_writer out;
   bool opened;
 public:
