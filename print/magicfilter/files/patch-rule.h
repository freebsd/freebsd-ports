--- rule.h.orig	2002-07-11 23:23:43 UTC
+++ rule.h
@@ -55,7 +55,7 @@ struct rule {
     struct rule *next;		/* next rule in the chain */
 } ;
 
-extern struct rule *getline(FILE *);
+extern struct rule *get_line(FILE *);
 extern struct rule *rules;
 char * action_p(enum rule_action);
 
