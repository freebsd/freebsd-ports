--- src/main.c	2010-05-05 01:49:36.000000000 +0400
+++ src/main.c	2012-01-06 21:36:53.000000000 +0300
@@ -51,7 +51,7 @@
     engines = ibus_component_get_engines (component);
     for (p = engines; p != NULL; p = p->next) {
         IBusEngineDesc *engine = (IBusEngineDesc *)p->data;
-        ibus_factory_add_engine (factory, engine->name, IBUS_TYPE_KMFL_ENGINE);
+        ibus_factory_add_engine (factory, ibus_engine_desc_get_name (engine), IBUS_TYPE_KMFL_ENGINE);
     }
 
     if (ibus) {
