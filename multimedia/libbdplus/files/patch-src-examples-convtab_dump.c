--- src/examples/convtab_dump.c.orig	2015-02-25 15:53:16.000000000 +0100
+++ src/examples/convtab_dump.c	2015-02-25 16:01:33.000000000 +0100
@@ -29,7 +29,7 @@
 // raw table
 #define MAX_TAB_SIZE 64*1024*1024
 uint8_t tab[MAX_TAB_SIZE];
-uint32_t index[0xffff];
+static uint32_t index[0xffff];
 
 static size_t _read_tab(const char *file)
 {
