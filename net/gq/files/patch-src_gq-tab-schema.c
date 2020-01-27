--- src/gq-tab-schema.c.orig	2008-01-09 16:35:12 UTC
+++ src/gq-tab-schema.c
@@ -1902,7 +1902,6 @@ gq_tab_schema_init(GqTabSchema* self)
 
      tab->content = schemamode_vbox;
      gtk_object_set_data(GTK_OBJECT(tab->content), "tab", tab);
-     return tab;
 }
 
 static void
