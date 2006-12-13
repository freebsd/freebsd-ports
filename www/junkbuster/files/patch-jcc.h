--- jcc.h.orig	Thu Dec 14 06:48:38 2006
+++ jcc.h	Thu Dec 14 06:48:47 2006
@@ -43,11 +43,6 @@
 extern char *uagent;
 extern char *from;
 
-extern struct list       wafer_list[];
-extern struct list        xtra_list[];
-extern struct list       trust_info[];
-extern struct url_spec * trust_list[];
-
 extern int add_forwarded;
 
 typedef struct http_request	*dummy_predecl1;
@@ -100,6 +95,11 @@
 	struct list *last;
 	struct list *next;
 };
+
+extern struct list       wafer_list[];
+extern struct list        xtra_list[];
+extern struct list       trust_info[];
+extern struct url_spec * trust_list[];
 
 #define IOB_PEEK(CSP) ((CSP->iob->cur > CSP->iob->eod) ? (CSP->iob->eod - CSP->iob->cur) : 0)
 #define IOB_RESET(CSP) if(CSP->iob->buf) free(CSP->iob->buf); memset(CSP->iob, '\0', sizeof(CSP->iob));
