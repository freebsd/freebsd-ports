--- libdpe/pe_update.c.orig	2015-01-16 09:50:40.000000000 +0100
+++ libdpe/pe_update.c	2015-01-16 09:50:47.000000000 +0100
@@ -75,7 +75,7 @@ write_file(Pe *pe, off_t size, size_t sh
 	return size;
 }
 
-loff_t
+off_t
 pe_update(Pe *pe, Pe_Cmd cmd)
 {
 	if (cmd != PE_C_NULL && cmd != PE_C_WRITE && cmd != PE_C_WRITE_MMAP) {
