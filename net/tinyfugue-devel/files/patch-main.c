--- src/main.c.orig	2026-11-19 10:23:15 UTC
+++ src/main.c
@@ -40,6 +40,8 @@ extern struct World   *world_decl;     /* declares str
 
 extern struct World   *world_decl;     /* declares struct World */
 
+extern void main_loop(void);
+
 const char sysname[] = UNAME;
 
 /* For customized versions, please add a unique identifer (e.g., your initials)
