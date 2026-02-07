--- libgssdp/gssdp-resource-group.h.orig	2018-11-30 23:17:04 UTC
+++ libgssdp/gssdp-resource-group.h
@@ -44,7 +44,6 @@ struct _GSSDPResourceGroupClass {
         void (* _gssdp_reserved3) (void);
         void (* _gssdp_reserved4) (void);
 };
-typedef struct _GSSDPResourceGroupClass GSSDPResourceGroupClass;
 
 GSSDPResourceGroup *
 gssdp_resource_group_new                 (GSSDPClient        *client);
