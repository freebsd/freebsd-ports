--- Optimizer/zend_inference.c.orig	2017-12-12 12:05:15 UTC
+++ Optimizer/zend_inference.c
@@ -2928,7 +2928,7 @@ static int zend_update_type_info(const z
 			break;
 		case ZEND_FE_FETCH_R:
 		case ZEND_FE_FETCH_RW:
-			tmp = (t2 & MAY_BE_REF);
+		    tmp = t2;
 			if (t1 & MAY_BE_OBJECT) {
 				if (opline->opcode == ZEND_FE_FETCH_RW) {
 					tmp |= MAY_BE_REF | MAY_BE_ANY | MAY_BE_ARRAY_KEY_ANY | MAY_BE_ARRAY_OF_ANY | MAY_BE_ARRAY_OF_REF;
@@ -2953,7 +2953,7 @@ static int zend_update_type_info(const z
 			}
 			UPDATE_SSA_TYPE(tmp, ssa_ops[i].op2_def);
 			if (ssa_ops[i].result_def >= 0) {
-				tmp = 0;
+				tmp = (ssa_ops[i].result_use >= 0) ? RES_USE_INFO() : 0;
 				if (t1 & MAY_BE_OBJECT) {
 					tmp |= MAY_BE_RC1 | MAY_BE_RCN | MAY_BE_ANY | MAY_BE_ARRAY_KEY_ANY | MAY_BE_ARRAY_OF_ANY | MAY_BE_ARRAY_OF_REF;
 				}
@@ -3079,7 +3079,8 @@ static int zend_update_type_info(const z
 					UPDATE_SSA_TYPE(tmp, ssa_ops[i].op1_def);
 				} else {
 					/* invalid key type */
-					UPDATE_SSA_TYPE(t1, ssa_ops[i].op1_def);
+					tmp = (tmp & (MAY_BE_RC1|MAY_BE_RCN)) | (t1 & ~(MAY_BE_RC1|MAY_BE_RCN));
+					UPDATE_SSA_TYPE(tmp, ssa_ops[i].op1_def);
 				}
 				COPY_SSA_OBJ_TYPE(ssa_ops[i].op1_use, ssa_ops[i].op1_def);
 			}
