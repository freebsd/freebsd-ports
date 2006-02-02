--- optimize.c.orig	Thu Nov 17 21:25:11 2005
+++ optimize.c	Thu Feb  2 09:40:00 2006
@@ -64,7 +64,6 @@ typedef struct _BBlink {
   struct _BBlink* next;
 } BBlink;
 
-#if 0
 static void dump_bb(BB* bb, zend_op_array *op_array) {
   BB* p = bb;
   BBlink *q;
@@ -130,7 +129,45 @@ static void dump_bb(BB* bb, zend_op_arra
   zend_printf("</pre><hr>\n");
   fflush(stdout);
 }
-#endif
+
+static void dump_array(int nb,void *pos,char type)
+{  int j;
+
+   switch(type) {
+   case 'i': {
+     int *ptr=pos;
+     for (j=0;j<nb;j++) {
+       zend_printf("%d:%6d ",j,*ptr);
+       ptr++;
+     }
+   }
+   break; 
+   case 'x': {
+     int *ptr=pos;
+     for (j=0;j<nb;j++) {
+       zend_printf("%d:%x ",j,*ptr);
+       ptr++;
+     }
+   }
+   break; 
+   case 'c': {
+     unsigned char *ptr=pos;
+     for (j=0;j<nb;j++) {
+/*       if (*ptr>=32 && *ptr<128) zend_printf("%d:%c",j,*ptr);
+       else if (*ptr>=128) zend_printf("%d:%2x",j,*ptr);
+       else if (*ptr<16) zend_printf("%d:&%1x",j,*ptr);
+       else zend_printf("%d:$%1x",j,(*ptr)-16); */
+       zend_printf("%d:%1x ",j,*ptr);
+       ptr++;
+     }
+   }
+   break;   
+   default:
+     for (j=0;j<nb;j++)
+       zend_printf("# ");
+   }
+   zend_printf("<br>\n");
+}
 
 #define SET_TO_NOP(op) \
   (op)->opcode = ZEND_NOP; \
@@ -250,14 +287,27 @@ static void compute_live_var(BB* bb, zen
                }
                break;
              case ZEND_UNSET_VAR:
+#ifndef ZEND_ENGINE_2_1
+/* Pre-PHP 5.1 only */
              case ZEND_UNSET_DIM_OBJ:
                end->result.op_type = IS_UNUSED;
                break;
+#else
+             case ZEND_UNSET_DIM:
+             case ZEND_UNSET_OBJ:
+               end->result.op_type = IS_UNUSED;
+               break;
+#endif
              case ZEND_RECV:
              case ZEND_RECV_INIT:
              /*case ZEND_ADD_ARRAY_ELEMENT:*/
              case ZEND_INCLUDE_OR_EVAL:
+#ifndef ZEND_ENGINE_2_1
+/* Pre-PHP 5.1 only */
              case ZEND_JMP_NO_CTOR:
+#else
+             case ZEND_NEW:
+#endif
              case ZEND_FE_FETCH:
 #ifdef ZEND_ENGINE_2
              case ZEND_ASSIGN_DIM:
@@ -1279,7 +1329,12 @@ jmp_nz_ex:
               goto jmp_nz;
             }
             goto jmp_2;
+#ifndef ZEND_ENGINE_2_1
+/* Pre-PHP 5.1 only */
           case ZEND_JMP_NO_CTOR:
+#else
+          case ZEND_NEW:
+#endif
           case ZEND_FE_FETCH:
 jmp_2:
             while (p->jmp_2->len == 1 && p->jmp_2->start->opcode == ZEND_JMP) {
@@ -1714,6 +1769,7 @@ static void optimize_bb(BB* bb, zend_op_
       }
     } else 
 #endif
+
     if ((op->opcode == ZEND_ADD ||
                 op->opcode == ZEND_SUB ||
                 op->opcode == ZEND_MUL ||
@@ -2443,7 +2499,13 @@ else if (prev != NULL &&
           op->opcode == ZEND_DO_FCALL_BY_NAME ||
           op->opcode == ZEND_POST_INC ||
           op->opcode == ZEND_POST_DEC ||
+#ifndef ZEND_ENGINE_2_1
+/* Pre-PHP 5.1 only */
           op->opcode == ZEND_UNSET_DIM_OBJ ||
+#else
+          op->opcode == ZEND_UNSET_DIM ||
+          op->opcode == ZEND_UNSET_OBJ ||
+#endif
           op->opcode == ZEND_INCLUDE_OR_EVAL
 #ifdef ZEND_ENGINE_2
           || op->opcode == ZEND_ASSIGN_DIM
@@ -2721,7 +2783,13 @@ static int build_cfg(zend_op_array *op_a
 			case ZEND_JMPNZ:
 			case ZEND_JMPZ_EX:
 			case ZEND_JMPNZ_EX:
+#ifndef ZEND_ENGINE_2_1
+/* Pre-PHP 5.1 only */
 			case ZEND_JMP_NO_CTOR:
+#else
+			case ZEND_NEW:
+			case ZEND_FE_RESET:
+#endif
 			case ZEND_FE_FETCH:
 				bb[line_num+1].start = op+1;
 				bb[op->op2.u.opline_num].start = &op_array->opcodes[op->op2.u.opline_num];
@@ -2840,9 +2908,19 @@ cont_failed:
 				break;
 #endif
 			case ZEND_UNSET_VAR:
+#ifndef ZEND_ENGINE_2_1
+/* Pre-PHP 5.1 only */
 			case ZEND_UNSET_DIM_OBJ:
 				op->result.op_type = IS_UNUSED;
 				break;
+#else
+			case ZEND_UNSET_DIM:
+				op->result.op_type = IS_UNUSED;
+				break;
+			case ZEND_UNSET_OBJ:
+				op->result.op_type = IS_UNUSED;
+				break;
+#endif
 			default:
 				break;
 		}
@@ -2894,7 +2972,13 @@ cont_failed:
 				case ZEND_JMPNZ:
 				case ZEND_JMPZ_EX:
 				case ZEND_JMPNZ_EX:
+#ifndef ZEND_ENGINE_2_1
+/* Pre-PHP 5.1 only */
 				case ZEND_JMP_NO_CTOR:
+#else
+				case ZEND_NEW:
+				case ZEND_FE_RESET:
+#endif
 				case ZEND_FE_FETCH:
 					p->jmp_2 = &bb[op->op2.u.opline_num];
 					p->follow = &bb[line_num];
@@ -3109,6 +3193,7 @@ void reassign_registers(zend_op_array *o
 
       while (start < op) {
         --op;
+        /* zend_printf("op=%d\n", op-op_array->opcodes); */
 #ifdef ZEND_ENGINE_2
         op_data = NULL;
 #else
@@ -3151,20 +3236,6 @@ void reassign_registers(zend_op_array *o
           GET_REG(r);
           op->extended_value = VAR_VAL(assigned[r]);
         }
-        if (op->opcode == ZEND_OP_DATA) {
-          op_data = op;
-          --op;
-          if (op->op1.op_type == IS_VAR || op->op1.op_type == IS_TMP_VAR) {
-            int r = VAR_NUM(op->op1.u.var);
-            GET_REG(r);
-            op->op1.u.var = VAR_VAL(assigned[r]);
-          }
-          if (op->op2.op_type == IS_VAR || op->op2.op_type == IS_TMP_VAR) {
-            int r = VAR_NUM(op->op2.u.var);
-            GET_REG(r);
-            op->op2.u.var = VAR_VAL(assigned[r]);
-          }
-        }
 #endif
         if (op->result.op_type == IS_VAR ||
             op->result.op_type == IS_TMP_VAR) {
@@ -3192,11 +3263,6 @@ void reassign_registers(zend_op_array *o
             }
           }
         }
-#ifdef ZEND_ENGINE_2
-        if (op_data != NULL && op_data->op2.op_type == IS_VAR) {
-          FREE_REG(VAR_NUM(op_data->op2.u.var));
-        }
-#endif
       }
     }
     p = p->next;
@@ -3279,6 +3345,7 @@ void eaccelerator_optimize(zend_op_array
     /* Store Optimized Code */
     emit_cfg(op_array, bb);
     reassign_registers(op_array, bb, global);
+    /* dump_bb(bb, op_array); */
 
     free_alloca(global);
   }
