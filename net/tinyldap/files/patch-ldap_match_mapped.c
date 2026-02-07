--- ldap_match_mapped.c.orig	2017-03-19 11:47:19 UTC
+++ ldap_match_mapped.c
@@ -14,7 +14,7 @@ extern uint32 magic,attribute_count,record_count,indic
 extern uint32 dn_ofs,objectClass_ofs;
 
 int substringmatch(struct Substring* x,const char* attr,int ignorecase) {
-  int (*diff)(const void* a, unsigned long len, const void* b);
+  int (*diff)(const void* a, size_t len, const void* b);
   if (ignorecase)
     diff=case_diffb;
   else
