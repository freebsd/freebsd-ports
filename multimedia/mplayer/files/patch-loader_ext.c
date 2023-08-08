--- loader/ext.c.orig	2021-01-23 18:22:09 UTC
+++ loader/ext.c
@@ -444,7 +444,7 @@ LPVOID WINAPI VirtualAlloc(LPVOID address, DWORD size,
 
     if (type&MEM_RESERVE && (unsigned)address&0xffff) {
 	size += (unsigned)address&0xffff;
-	address = (unsigned)address&~0xffff;
+	address = (void*)((unsigned)address&~0xffff);
     }
     pgsz = sysconf(_SC_PAGESIZE);
     if (type&MEM_COMMIT && (unsigned)address%pgsz) {
