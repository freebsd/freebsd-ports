--- libgssdp/gssdp-client.h.orig	2018-12-10 21:21:06 UTC
+++ libgssdp/gssdp-client.h
@@ -31,9 +31,6 @@ G_BEGIN_DECLS
 
 G_DECLARE_DERIVABLE_TYPE (GSSDPClient, gssdp_client, GSSDP, CLIENT, GObject)
 
-typedef struct _GSSDPClient GSSDPClient;
-typedef struct _GSSDPClientClass GSSDPClientClass;
-
 /**
  * GSSDPUDAVersion:
  * @GSSDP_UDA_VERSION_UNSPECIFIED: When creating a client, use the default version
