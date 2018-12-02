--- libgssdp/gssdp-client.h.orig	2018-11-30 23:11:39 UTC
+++ libgssdp/gssdp-client.h
@@ -31,9 +31,6 @@ G_BEGIN_DECLS
 
 G_DECLARE_DERIVABLE_TYPE (GSSDPClient, gssdp_client, GSSDP, CLIENT, GObject)
 
-typedef struct _GSSDPClient GSSDPClient;
-typedef struct _GSSDPClientClass GSSDPClientClass;
-
 struct _GSSDPClientClass {
         GObjectClass parent_class;
 
