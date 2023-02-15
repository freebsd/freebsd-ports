--- detail-domain.c.orig	1993-04-22 20:39:51 UTC
+++ detail-domain.c
@@ -199,6 +199,7 @@ p_type(type)
       case T_ANY:		/* matches any type */
 	strcpy(type_buf, "ANY");
 	break;
+#ifdef T_UNSPEC	
       case T_UINFO:
 	strcpy(type_buf, "UINFO");
 	break;
@@ -211,6 +212,7 @@ p_type(type)
       case T_UNSPEC:
 	strcpy(type_buf, "UNSPEC");
         break;
+#endif        
       default:
 	sprintf(type_buf, "%d", type);
         break;
@@ -633,6 +635,7 @@ p_ans(msg, eom)
 	printf("; errors = %s\n", str);
 	MARK_WINDOW();
 
+#ifdef T_UNSPEC
       case T_UINFO:
         printf("    UINFO: ");
         printf("%s\n", cp);
@@ -654,6 +657,12 @@ p_ans(msg, eom)
 	MARK_WINDOW();
         break;
 
+      case T_UNSPEC:
+	printf("    <binary data, see hex dump below>\n");
+	INCR_PTRS(rdlength);
+	MARK_WINDOW();
+	break;
+#endif
       case T_WKS:
         if (rdlength < (int)(sizeof(u_long) + 1))
             break;
@@ -730,11 +739,6 @@ p_ans(msg, eom)
 	break;
 
 
-      case T_UNSPEC:
-	printf("    <binary data, see hex dump below>\n");
-	INCR_PTRS(rdlength);
-	MARK_WINDOW();
-	break;
 
 
       default:
