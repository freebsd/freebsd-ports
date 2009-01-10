--- common/seahorse-registry.h.orig	2008-11-23 18:26:42.000000000 -0500
+++ common/seahorse-registry.h	2008-11-23 18:26:47.000000000 -0500
@@ -35,6 +35,7 @@ G_BEGIN_DECLS
 
 typedef struct _SeahorseRegistry      SeahorseRegistry;
 typedef struct _SeahorseRegistryClass SeahorseRegistryClass;
+typedef struct _SeahorseRegistryType  SeahorseRegistryType;
 
 struct _SeahorseRegistry {
 	 GObject parent;
@@ -44,6 +45,10 @@ struct _SeahorseRegistryClass {
 	GObjectClass parent_class;
 };
 
+struct _SeahorseRegistryType {
+	GType type;
+};
+
 /* member functions */
 GType                seahorse_registry_get_type        (void) G_GNUC_CONST;
 
