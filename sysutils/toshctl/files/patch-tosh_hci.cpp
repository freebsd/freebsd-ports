--- tosh_hci.cpp.orig
+++ tosh_hci.cpp
@@ -22,7 +22,8 @@
 static const char PROGRAM_ID[]="$Id: tosh_hci.cpp,v 1.5 2003/07/29 01:43:38 cws Exp $";
 
 #include "tosh_hci.h"
-#include <stdio.h>
+#include <cstdio>
+#include <cstdlib>
 
 CToshVar* initToshHCI()
 {
@@ -159,10 +160,10 @@
     unsigned result_a,result_c;
   
     asm ("inb $0xb2,%%al\n\t"
-            "jc hci_call_error\n\t"
+            "jc 0f\n\t"
             "movl %%ecx,%%eax\n\t"
             "xor  %%eax,%%eax\n"
-            "hci_call_error:"
+            "0:"
         : "=a" (result_a) ,"=c" (result_c)
         : "a" (eax), "b" (ebx), "c" (ecx), "d" (edx));
