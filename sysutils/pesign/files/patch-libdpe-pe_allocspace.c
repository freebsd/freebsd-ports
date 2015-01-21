--- libdpe/pe_allocspace.c.orig	2014-10-24 21:51:06.000000000 +0200
+++ libdpe/pe_allocspace.c	2015-01-16 09:58:52.000000000 +0100
@@ -19,6 +19,7 @@
 
 #include "libdpe.h"
 
+#include <err.h>
 #include <unistd.h>
 #include <sys/mman.h>
 #include <sys/types.h>
@@ -83,6 +84,7 @@ pe_set_image_size(Pe *pe)
 int
 pe_extend_file(Pe *pe, size_t size, uint32_t *new_space, int align)
 {
+	int error;
 	void *new = NULL;
 
 	if (align)
@@ -93,9 +95,13 @@ pe_extend_file(Pe *pe, size_t size, uint
 	if (rc < 0)
 		return -1;
 
-	new = mremap(pe->map_address, pe->maximum_size,
-		pe->maximum_size + extra, MREMAP_MAYMOVE);
+	error = munmap(pe->map_address, pe->maximum_size);
+	if (error != 0)
+		err(1, "munmap");
+	new = mmap(pe->map_address, pe->maximum_size + extra,
+	    PROT_WRITE | PROT_READ, MAP_SHARED, pe->fildes, 0);
 	if (new == MAP_FAILED) {
+		err(1, "mmap");
 		__libpe_seterrno (PE_E_NOMEM);
 		return -1;
 	}
@@ -116,10 +122,15 @@ int
 pe_shorten_file(Pe *pe, size_t size)
 {
 	void *new = NULL;
+	int error;
 
-	new = mremap(pe->map_address, pe->maximum_size,
-		pe->maximum_size - size, 0);
+	error = munmap(pe->map_address, pe->maximum_size);
+	if (error != 0)
+		err(1, "munmap");
+
+	new = mmap(pe->map_address, pe->maximum_size - size, PROT_READ | PROT_WRITE, MAP_SHARED, pe->fildes, 0);
 	if (new == MAP_FAILED) {
+		err(1, "mmap");
 		__libpe_seterrno (PE_E_NOMEM);
 		return -1;
 	}
