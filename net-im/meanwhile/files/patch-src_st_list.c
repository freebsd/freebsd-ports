===================================================================
RCS file: /cvsroot/meanwhile/meanwhile/src/st_list.c,v
retrieving revision 1.7
retrieving revision 1.9
diff -u -r1.7 -r1.9
--- src/st_list.c	2004/06/27 22:26:44	1.7
+++ src/st_list.c	2004/06/30 20:13:11	1.9
@@ -29,6 +29,7 @@
   struct mwIdBlock id;
   char *name;
   char *alias;
+  char type;
 };
 
 
@@ -99,11 +100,24 @@
 
 GList *mwSametimeList_getGroups(struct mwSametimeList *l) {
   GList *list = NULL;
+
+  g_return_val_if_fail(l != NULL, NULL);
+
   g_hash_table_foreach(l->groups, collect, &list);
   return list;
 }
 
 
+struct mwSametimeGroup *mwSametimeList_getGroup(struct mwSametimeList *l,
+						const char *name) {
+  g_return_val_if_fail(l != NULL, NULL);
+  g_return_val_if_fail(name != NULL, NULL);
+  g_return_val_if_fail(strlen(name) > 0, NULL);
+
+  return (struct mwSametimeGroup *) g_hash_table_lookup(l->groups, name);
+}
+
+
 void mwSametimeList_setMajor(struct mwSametimeList *l, guint v) {
   g_return_if_fail(l != NULL);
   l->ver_major = v;
@@ -174,6 +188,23 @@
 }
 
 
+void mwSametimeGroup_setName(struct mwSametimeGroup *g, const char *name) {
+  struct mwSametimeList *l;
+
+  g_return_if_fail(g != NULL);
+  g_return_if_fail(name != NULL);
+  g_return_if_fail(strlen(name) > 0);
+
+  l = g->list;
+  g_hash_table_remove(l->groups, g->name);
+
+  g_free(g->name);
+  g->name = g_strdup(name);
+
+  g_hash_table_insert(l->groups, g->name, g);
+}
+
+
 gboolean mwSametimeGroup_isOpen(struct mwSametimeGroup *g) {
   g_return_val_if_fail(g != NULL, FALSE);
   return g->open;
@@ -370,7 +401,7 @@
 static int get_user(char *b, struct mwSametimeList *l,
 		    struct mwSametimeGroup *g) {
 
-  char *name, *alias = NULL;
+  char *id, *name, *alias = NULL;
   char *tmp;
 
   struct mwIdBlock idb = { NULL, NULL };
@@ -379,25 +410,28 @@
   g_return_val_if_fail(strlen(b) > 2, -1);
   g_return_val_if_fail(g != NULL, -1);
 
-  idb.user = b + 2; /* advance past "U " */
+  /* just get everything now */
+  str_replace(b, ';', ' ');
+
+  id = b + 2; /* advance past "U " */
   tmp = strstr(b, "1:: "); /* backwards thinking saves overruns */
   if(! tmp) return -1;
   *tmp = '\0';
-  str_replace(idb.user, ';', ' ');
   b = tmp;
 
   name = b + 4; /* advance past the "1:: " */
-  tmp = strchr(name, ',');
+
+  tmp = strrchr(name, ',');
   if(tmp) {
     *tmp = '\0';
-
+   
     tmp++;
     if(*tmp) {
-      str_replace(tmp, ';', ' ');
       alias = tmp;
     }
   }
   
+  idb.user = id;
   user = mwSametimeUser_new(g, &idb, name, alias);
 
   return 0;
@@ -477,6 +511,8 @@
   if(name) str_replace(name, ' ', ';');
   if(alias) str_replace(alias, ' ', ';');
 
+  if(!name && alias) name = g_strdup(alias);
+
   writ = g_sprintf(*b, "U %s1:: %s,%s\n",
 		   id, name? name: id, alias? alias: "");
 
