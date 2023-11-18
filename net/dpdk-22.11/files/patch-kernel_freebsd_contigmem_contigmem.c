--- kernel/freebsd/contigmem/contigmem.c.orig	2023-05-20 00:00:38 UTC
+++ kernel/freebsd/contigmem/contigmem.c
@@ -111,7 +111,7 @@ static int
 };
 
 static int
-contigmem_load()
+contigmem_load(void)
 {
 	char index_string[8], description[32];
 	int  i, error = 0;
@@ -178,7 +178,7 @@ static int
 }
 
 static int
-contigmem_unload()
+contigmem_unload(void)
 {
 	int i;
 
