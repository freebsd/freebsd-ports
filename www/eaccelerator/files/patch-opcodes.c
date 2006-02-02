--- opcodes.c.orig	Mon May 16 11:56:42 2005
+++ opcodes.c	Thu Feb  2 09:40:00 2006
@@ -43,11 +43,7 @@
 #  define OP1_VAR_2 OP1_VAR
 #endif
 
-#ifdef ZEND_ENGINE_2
-#  define LAST_OPCODE 149
-#else
-#  define LAST_OPCODE 106
-#endif
+#define LAST_OPCODE (sizeof(opcodes)/sizeof(opcodes[0]))
 
 static const opcode_dsc opcodes[] = {
   OPDEF("NOP",                       EXT_UNUSED | OP1_UNUSED | OP2_UNUSED | RES_UNUSED), /* 0 */
@@ -158,16 +154,20 @@ static const opcode_dsc opcodes[] = {
   OPDEF("INIT_ARRAY",                EXT_BIT    | OP1_STD    | OP2_STD    | RES_TMP), /* 71 */
   OPDEF("ADD_ARRAY_ELEMENT",         EXT_BIT    | OP1_STD    | OP2_STD    | RES_TMP), /* 72 */
   OPDEF("INCLUDE_OR_EVAL",           EXT_UNUSED | OP1_STD    | OP2_INCLUDE| RES_VAR), /* 73 */
-#ifdef ZEND_ENGINE_2
+#ifdef ZEND_ENGINE_2_1
+  /* php 5.1 and up */
   OPDEF("UNSET_VAR",                 EXT_UNUSED | OP1_STD    | OP2_FETCH  | RES_UNUSED), /* 74 */
-  OPDEF("UNSET_DIM_OBJ",             EXT_STD    | OP1_STD    | OP2_STD    | RES_UNUSED), /* 75 */
-  OPDEF("ISSET_ISEMPTY",             EXT_ISSET  | OP1_VAR    | OP2_UNUSED | RES_TMP), /* 76 */
+  OPDEF("UNSET_DIM",                 EXT_STD    | OP1_STD    | OP2_STD    | RES_UNUSED), /* 75 */
+  OPDEF("UNSET_OBJ",                 EXT_STD    | OP1_STD    | OP2_STD    | RES_UNUSED), /* 76 */
+  OPDEF("FE_RESET",                  EXT_BIT    | OP1_STD    | OP2_OPLINE | RES_VAR), /* 77 */
 #else
+  /* <= php 5.0 */
+  /* though there is no ISSET_ISEMPTY in php 5.0 it's better to leave it here i guess */
   OPDEF("UNSET_VAR",                 EXT_UNUSED | OP1_STD    | OP2_UNUSED | RES_UNUSED), /* 74 */
   OPDEF("UNSET_DIM_OBJ",             EXT_UNUSED | OP1_VAR    | OP2_STD    | RES_UNUSED), /* 75 */
   OPDEF("ISSET_ISEMPTY",             EXT_UNUSED | OP1_VAR    | OP2_ISSET  | RES_TMP), /* 76 */
-#endif
   OPDEF("FE_RESET",                  EXT_BIT    | OP1_STD    | OP2_UNUSED | RES_VAR), /* 77 */
+#endif
   OPDEF("FE_FETCH",                  EXT_FE     | OP1_STD    | OP2_OPLINE | RES_TMP), /* 78 */
   OPDEF("EXIT",                      EXT_UNUSED | OP1_STD    | OP2_UNUSED | RES_UNUSED), /* 79 */
   OPDEF("FETCH_R",                   EXT_UNUSED | OP1_STD    | OP2_FETCH  | RES_VAR), /* 80 */
@@ -234,7 +234,7 @@ static const opcode_dsc opcodes[] = {
   OPDEF("POST_INC_OBJ",              EXT_UNUSED | OP1_STD    | OP2_STD    | RES_TMP), /* 134 */
   OPDEF("POST_DEC_OBJ",              EXT_UNUSED | OP1_STD    | OP2_STD    | RES_TMP), /* 135 */
   OPDEF("ASSIGN_OBJ",                EXT_UNUSED | OP1_STD    | OP2_STD    | RES_VAR), /* 136 */
-  OPDEF("OP_DATA",                   EXT_UNUSED | OP1_STD    | OP2_STD    | RES_UNUSED), /* 137 */
+  OPDEF("OP_DATA",                   EXT_UNUSED | OP1_STD    | OP2_STD    | RES_STD), /* 137 */
   OPDEF("INSTANCEOF",                EXT_UNUSED | OP1_STD    | OP2_CLASS  | RES_TMP), /* 138 */
   OPDEF("DECLARE_CLASS",             EXT_UNUSED | OP1_STD    | OP2_STD    | RES_CLASS), /* 139 */
   OPDEF("DECLARE_INHERITED_CLASS",   EXT_CLASS  | OP1_STD    | OP2_STD    | RES_CLASS), /* 140 */
@@ -245,14 +245,17 @@ static const opcode_dsc opcodes[] = {
   OPDEF("VERIFY_INSTANCEOF",         EXT_UNUSED | OP1_CLASS  | OP2_STD    | RES_UNUSED), /* 145 */
   OPDEF("VERIFY_ABSTRACT_CLASS",     EXT_UNUSED | OP1_CLASS  | OP2_UNUSED | RES_UNUSED), /* 146 */
   OPDEF("ASSIGN_DIM",                EXT_UNUSED | OP1_STD    | OP2_STD    | RES_VAR),  /* 147 */
-
   OPDEF("ISSET_ISEMPTY_PROP_OBJ",    EXT_ISSET  | OP1_STD    | OP2_STD    | RES_TMP), /* 148 */
   OPDEF("HANDLE_EXCEPTION",          EXT_STD    | OP1_UNUSED | OP2_UNUSED | RES_STD)  /* 149 */
+# ifdef ZEND_ENGINE_2_1
+  ,
+  OPDEF("USER_OPCODE",               EXT_STD    | OP1_UNUSED | OP2_UNUSED | RES_STD)  /* 150 */
+# endif    
 #endif
 };
 
 const opcode_dsc* get_opcode_dsc(unsigned int n) {
-  if (n <= LAST_OPCODE) {
+  if (n < LAST_OPCODE) {
     return &opcodes[n];
   } else {
     return NULL;
@@ -261,17 +264,17 @@ const opcode_dsc* get_opcode_dsc(unsigne
 #endif
 
 #ifdef ZEND_ENGINE_2
-static opcode_handler_t eaccelerator_opcode_handlers[LAST_OPCODE+1];
+static opcode_handler_t eaccelerator_opcode_handlers[LAST_OPCODE];
 static int handlers_retrived = 0;
 
 ZEND_DLEXPORT void retrive_opcode_handlers_handler(zend_op_array *op_array) {
   unsigned char i;
   efree(op_array->opcodes);
-  op_array->opcodes = (zend_op*)emalloc(sizeof(zend_op)*(LAST_OPCODE+1));
-  op_array->last = LAST_OPCODE+1;
-  op_array->size = LAST_OPCODE+1;
+  op_array->opcodes = (zend_op*)emalloc(sizeof(zend_op)*(LAST_OPCODE));
+  op_array->last = LAST_OPCODE;
+  op_array->size = LAST_OPCODE;
   op_array->T    = 0;
-  for (i=0; i<=LAST_OPCODE; i++) {
+  for (i=0; i<LAST_OPCODE; i++) {
     op_array->opcodes[i].opcode = i;
     op_array->opcodes[i].op1.op_type = IS_UNUSED;
     op_array->opcodes[i].op1.u.opline_num = i;
@@ -298,9 +301,9 @@ static int retrive_opcode_handlers(TSRML
     ext->op_array_handler = retrive_opcode_handlers_handler;
     p = compile_string(&str, empty_string TSRMLS_CC);
     ext->op_array_handler = old;
-    if (p != NULL && p->last == LAST_OPCODE+1) {
+    if (p != NULL && p->last == (LAST_OPCODE - 1)) {
       int i = 0;
-      while (i <= LAST_OPCODE) {
+      while (i < LAST_OPCODE) {
          eaccelerator_opcode_handlers[p->opcodes[i].opcode] = p->opcodes[i].handler;
          ++i;
       }
@@ -318,7 +321,7 @@ opcode_handler_t get_opcode_handler(zend
       return NULL;
     }
   }
-  if (opcode <= LAST_OPCODE) {
+  if (opcode < LAST_OPCODE) {
     return eaccelerator_opcode_handlers[opcode];
   } else {
     return (opcode_handler_t) NULL;
