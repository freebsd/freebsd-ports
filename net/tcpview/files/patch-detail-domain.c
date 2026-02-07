--- detail-domain.c.orig	1993-04-22 13:39:51.000000000 -0700
+++ detail-domain.c	2023-02-14 21:16:01.401668000 -0800
@@ -103,6 +103,7 @@
 
 #define FAIL 1
 #define SUCCEED 0
+#define IGNORE 0
 #define MIN(a,b) (((a)<(b))?(a):(b))
 
 
@@ -199,6 +200,7 @@
       case T_ANY:		/* matches any type */
 	strcpy(type_buf, "ANY");
 	break;
+#ifdef T_UNSPEC	
       case T_UINFO:
 	strcpy(type_buf, "UINFO");
 	break;
@@ -211,6 +213,7 @@
       case T_UNSPEC:
 	strcpy(type_buf, "UNSPEC");
         break;
+#endif        
       default:
 	sprintf(type_buf, "%d", type);
         break;
@@ -444,7 +447,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    Canonical name = %s\n", str);
 	MARK_WINDOW();
@@ -455,7 +458,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    MB domain name = %s\n", str);
 	MARK_WINDOW();
@@ -466,7 +469,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    MD domain name = %s (obsolete)\n", str);
 	MARK_WINDOW();
@@ -477,7 +480,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    MF domain name = %s (obsolete)\n", str);
 	MARK_WINDOW();
@@ -488,7 +491,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    Mail group member = %s\n", str);
 	MARK_WINDOW();
@@ -499,7 +502,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    Mail rename domain name = %s\n", str);
 	MARK_WINDOW();
@@ -512,7 +515,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    Mail exchangeer = %s, preference %u\n", str, pref);
 	MARK_WINDOW();
@@ -523,7 +526,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    Authoritative name server = %s\n", str);
 	MARK_WINDOW();
@@ -534,7 +537,7 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
         printf("    Domain name pointer = %s\n", str);
 	MARK_WINDOW();
@@ -568,7 +571,7 @@
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
 	    MARK_SAVED_WIN(saveind, -1, -1);
-	    return NULL;
+	    return IGNORE;
 	}
 	printf("      Origin: %s\n", str);
 	MARK_WINDOW();
@@ -578,7 +581,7 @@
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
 	    MARK_SAVED_WIN(saveind, -1, -1);
-	    return NULL;
+	    return IGNORE;
 	}
 	printf("      Mail Addr: %s\n", str);
 	MARK_WINDOW();
@@ -621,18 +624,19 @@
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
 	printf("    MINFO: requests = %s", str);
 	str = p_cdname(msg, eom);
         if (str == NULL) {
 	    printf(" ** Data truncated **\n");
 	    MARK_WINDOW_NONE();
-	    return NULL;
+	    return IGNORE;
 	}
 	printf("; errors = %s\n", str);
 	MARK_WINDOW();
 
+#ifdef T_UNSPEC
       case T_UINFO:
         printf("    UINFO: ");
         printf("%s\n", cp);
@@ -654,6 +658,12 @@
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
@@ -730,11 +740,6 @@
 	break;
 
 
-      case T_UNSPEC:
-	printf("    <binary data, see hex dump below>\n");
-	INCR_PTRS(rdlength);
-	MARK_WINDOW();
-	break;
 
 
       default:
