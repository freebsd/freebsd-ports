--- backend/src/c/xmlback/eval.c.orig	2015-10-24 14:59:57 UTC
+++ backend/src/c/xmlback/eval.c
@@ -198,9 +198,9 @@ ctx_clr (void) /*{{{*/
 static inline void
 check_error (void) /*{{{*/
 {
-	if (SLang_Error) {
+	if (SLang_get_error()) {
 		SLang_restart (1);
-		SLang_Error = 0;
+		SLang_set_error(0);
 	}
 }/*}}}*/
 static void
@@ -243,7 +243,7 @@ type_retrieve (int argc) /*{{{*/
 	int	dummy;
 
 	if (! (argv = (type_t *) malloc (argc * sizeof (type_t)))) {
-		SLang_Error = SL_MALLOC_ERROR;
+		SLang_set_error(SL_MALLOC_ERROR);
 		return NULL;
 	}
 	for (n = 0; n < argc; ++n)
@@ -262,7 +262,7 @@ type_retrieve (int argc) /*{{{*/
 				argv[n].v.n = (double) dummy;
 			break;
 		case SLANG_DOUBLE_TYPE:
-			if (SLang_pop_double (& argv[n].v.n, & dummy, & dummy) == -1)
+			if (SLang_pop_double (& argv[n].v.n) == -1)
 				st = false;
 			break;
 		case SLANG_STRING_TYPE:
@@ -901,7 +901,7 @@ SLin (void) /*{{{*/
 	
 	argc = SLang_Num_Function_Args;
 	if (argc < 2) {
-		SLang_Error = SL_SYNTAX_ERROR;
+		SLang_set_error(SL_SYNTAX_ERROR);
 		return -1;
 	}
 	rc = 0;
@@ -928,7 +928,7 @@ SLin (void) /*{{{*/
 						}
 				free (i);
 			} else {
-				SLang_Error = SL_MALLOC_ERROR;
+				SLang_set_error(SL_MALLOC_ERROR);
 				rc = -1;
 			}
 		}
@@ -940,7 +940,7 @@ SLin (void) /*{{{*/
 			
 			if (d = (double *) malloc (argc * sizeof (double))) {
 				for (n = 0; n < argc; ++n)
-					if (SLang_pop_double (& d[n], & dummy, & dummy) == -1) {
+					if (SLang_pop_double (& d[n]) == -1) {
 						rc = -1;
 						break;
 					}
@@ -952,7 +952,7 @@ SLin (void) /*{{{*/
 						}
 				free (d);
 			} else {
-				SLang_Error = SL_MALLOC_ERROR;
+				SLang_set_error(SL_MALLOC_ERROR);
 				rc = -1;
 			}
 		}
@@ -980,14 +980,14 @@ SLin (void) /*{{{*/
 				}
 				free (s);
 			} else {
-				SLang_Error = SL_MALLOC_ERROR;
+                SLang_set_error(SL_MALLOC_ERROR);
 				rc = -1;
 			}
 		}
 		break;
 	}
-	if ((rc == -1) && (! SLang_Error))
-		SLang_Error = SL_TYPE_MISMATCH;
+	if ((rc == -1) && (! SLang_get_error()))
+		SLang_set_error(SL_TYPE_MISMATCH);
 	return rc;
 }/*}}}*/
 static int
@@ -1000,7 +1000,7 @@ SLbetween (void) /*{{{*/
 	
 	argc = SLang_Num_Function_Args;
 	if (argc != 3) {
-		SLang_Error = SL_SYNTAX_ERROR;
+        SLang_set_error(SL_SYNTAX_ERROR);
 		return -1;
 	}
 	if (! (argv = type_retrieve (argc)))
@@ -1030,8 +1030,8 @@ SLbetween (void) /*{{{*/
 			break;
 		}
 	type_release (argc, argv);
-	if ((rc == -1) && (! SLang_Error))
-		SLang_Error = SL_TYPE_MISMATCH;
+	if ((rc == -1) && (! SLang_get_error()))
+        SLang_set_error(SL_TYPE_MISMATCH);
 	return rc;
 }/*}}}*/
 static void
@@ -1044,7 +1044,7 @@ SLdecode (void) /*{{{*/
 	
 	argc = SLang_Num_Function_Args;
 	if ((argc < 4) || (argc % 2 != 0)) {
-		SLang_Error = SL_SYNTAX_ERROR;
+		SLang_set_error(SL_SYNTAX_ERROR);
 		return;
 	}
 	if (! (argv = type_retrieve (argc)))
@@ -1068,7 +1068,7 @@ SLdecode (void) /*{{{*/
 		if (argv[argc - 1].type != argv[2].type)
 			st = false;
 	if (! st)
-		SLang_Error = SL_TYPE_MISMATCH;
+		SLang_set_error(SL_TYPE_MISMATCH);
 	else {
 		int	hit = -1;
 		
@@ -1092,7 +1092,7 @@ SLdecode (void) /*{{{*/
 		switch (argv[hit].type) {
 		default:
 			st = false;
-			SLang_Error = SL_TYPE_MISMATCH;
+			SLang_set_error(SL_TYPE_MISMATCH);
 			break;
 		case SLANG_INT_TYPE:
 			SLang_push_integer ((int) argv[hit].v.n);
