--- libdbsddisk/libdbsddisk.orig	Sat Nov 18 16:46:03 2006
+++ libdbsddisk/libdbsddisk.pro	Sat Nov 18 16:44:21 2006
@@ -23,38 +23,12 @@
            chunk.c \
            create_chunk.c \
            disk.c \
-           open_disk.c \
            rules.c \
+           write_$${ARCH}_disk.c \
            write_disk.c
 
 equals(ARCH, ia64) {
-	SOURCES += open_ia64_disk.c \
-              write_ia64_disk.c
+	SOURCES += open_ia64_disk.c
 } else {
-	SOURCES += change.c
-}
-
-equals(ARCH, alpha) {
-   SOURCES += write_alpha_disk.c
-}
-
-equals(ARCH, amd64) {
-   SOURCES += write_amd64_disk.c
-}
-
-equals(ARCH, sparc64) {
-	SOURCES += write_sparc64_disk.c
-}
-           
-equals(ARCH, i386) {
-	SOURCES += write_i386_disk.c
-}
-
-equals(ARCH, pc98) {
-	SOURCES += write_pc98_disk.c
-	DEFINES += PC98
-}
-
-equals(ARCH, powerpc) {
-	SOURCES += write_powerpc_disk.c
+	SOURCES += open_disk.c change.c
 }
