--- ldap_match_sre.c.orig	2007-06-28 22:17:33 UTC
+++ ldap_match_sre.c
@@ -45,7 +45,7 @@ static int ldap_match_present_sre(struct SearchResultE
 }
 
 static int substrmatch(struct Substring* x,struct string* s,int ignorecase) {
-  int (*diff)(const void* a, unsigned long len, const void* b);
+  int (*diff)(const void* a, size_t len, const void* b);
   if (ignorecase)
     diff=case_diffb;
   else
