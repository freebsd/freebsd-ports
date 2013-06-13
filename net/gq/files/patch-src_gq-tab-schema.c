diff --git src/gq-tab-schema.c src/gq-tab-schema.c
index b0f16e6..29219c0 100644
--- src/gq-tab-schema.c
+++ src/gq-tab-schema.c
@@ -1902,7 +1902,6 @@ gq_tab_schema_init(GqTabSchema* self)
 
      tab->content = schemamode_vbox;
      gtk_object_set_data(GTK_OBJECT(tab->content), "tab", tab);
-     return tab;
 }
 
 static void
