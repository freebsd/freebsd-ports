--- lib/loader/win32.c.orig	Thu Feb  1 05:23:25 2001
+++ lib/loader/win32.c	Sun Dec  7 13:04:23 2003
@@ -1094,12 +1094,12 @@
 {
 #warning FIXME
     if(s1)
-    dbgprintf("MultiByteToWideChar(codepage %d, flags 0x%x, string 0x%x='%s',
-	size %d, dest buffer 0x%x, dest size %d) => 1 ( L\"\\0\" )\n",
+    dbgprintf("MultiByteToWideChar(codepage %d, flags 0x%x, string 0x%x='%s',\
+	size %d, dest buffer 0x%x, dest size %d) => 1 ( L\"\\0\" )\n",\
 	    v1, v2, s1, s1, siz1, s2, siz2);
     else
-    dbgprintf("MultiByteToWideChar(codepage %d, flags 0x%x, string NULL,
-	size %d, dest buffer 0x%x, dest size %d) => 1 ( L\"\\0\" )\n",
+    dbgprintf("MultiByteToWideChar(codepage %d, flags 0x%x, string NULL,\
+	size %d, dest buffer 0x%x, dest size %d) => 1 ( L\"\\0\" )\n",\
 	    v1, v2, siz1, s2, siz2);
     
     if(s2==0)
@@ -1605,12 +1605,12 @@
 {
     long result=CreateFileMappingA(hFile, lpAttr, flProtect, dwMaxHigh, dwMaxLow, name);
     if(!name)
-    dbgprintf("CreateFileMappingA(file 0x%x, lpAttr 0x%x, 
-	flProtect 0x%x, dwMaxHigh 0x%x, dwMaxLow 0x%x, name 0) => %d\n",
+    dbgprintf("CreateFileMappingA(file 0x%x, lpAttr 0x%x,\
+	flProtect 0x%x, dwMaxHigh 0x%x, dwMaxLow 0x%x, name 0) => %d\n",\
 	    hFile, lpAttr, flProtect, dwMaxHigh, dwMaxLow, result);
     else
-    dbgprintf("CreateFileMappingA(file 0x%x, lpAttr 0x%x, 
-	flProtect 0x%x, dwMaxHigh 0x%x, dwMaxLow 0x%x, name 0x%x='%s') => %d\n",
+    dbgprintf("CreateFileMappingA(file 0x%x, lpAttr 0x%x,\
+	flProtect 0x%x, dwMaxHigh 0x%x, dwMaxLow 0x%x, name 0x%x='%s') => %d\n",\
 	    hFile, lpAttr, flProtect, dwMaxHigh, dwMaxLow, name, name, result);    
     return result;
 }    
