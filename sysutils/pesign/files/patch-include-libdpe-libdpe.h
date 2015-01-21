--- include/libdpe/libdpe.h.orig	2015-01-16 09:43:46.000000000 +0100
+++ include/libdpe/libdpe.h	2015-01-16 09:43:53.000000000 +0100
@@ -78,7 +78,7 @@ extern Pe *pe_begin(int fildes, Pe_Cmd c
 extern Pe *pe_clone(Pe *pe, Pe_Cmd cmd);
 extern Pe *pe_memory(char *image, size_t size);
 extern int pe_end(Pe *pe);
-extern loff_t pe_update(Pe *pe, Pe_Cmd cmd);
+extern off_t pe_update(Pe *pe, Pe_Cmd cmd);
 extern Pe_Kind pe_kind(Pe *Pe) __attribute__ ((__pure__));
 extern Pe_Scn *pe_nextscn(Pe *pe, Pe_Scn *scn);
 extern Pe_Scn *pe_getscn(Pe *pe, size_t idx);
