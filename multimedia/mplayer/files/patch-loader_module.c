--- loader/module.c.orig	2011-07-30 20:44:37 UTC
+++ loader/module.c
@@ -844,7 +844,7 @@ static int report_func(void *stack_base, int stack_siz
   // memory management:
   case 0x150011: //NewPtrClear
   case 0x150012: //NewPtrSysClear
-      reg->eax = malloc(((uint32_t *)stack_base)[1]);
+      reg->eax = (uint32_t)malloc(((uint32_t *)stack_base)[1]);
       memset((void *)reg->eax,0,((uint32_t *)stack_base)[1]);
 #ifdef DEBUG_QTX_API
       printf("%*sLEAVE(%d): EMULATED! 0x%X\n",ret_i*2,"",ret_i, reg->eax);
@@ -852,7 +852,7 @@ static int report_func(void *stack_base, int stack_siz
       return 1;
   case 0x15000F: //NewPtr
   case 0x150010: //NewPtrSys
-      reg->eax = malloc(((uint32_t *)stack_base)[1]);
+      reg->eax = (uint32_t)malloc(((uint32_t *)stack_base)[1]);
 #ifdef DEBUG_QTX_API
       printf("%*sLEAVE(%d): EMULATED! 0x%X\n",ret_i*2,"",ret_i, reg->eax);
 #endif
