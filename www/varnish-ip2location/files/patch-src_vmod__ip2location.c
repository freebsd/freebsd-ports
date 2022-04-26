--- src/vmod_ip2location.c.orig	2020-11-29 23:51:52 UTC
+++ src/vmod_ip2location.c
@@ -6,6 +6,11 @@
 
 #include <IP2Location.h>
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#define gcvt(v, d, c) sprintf(c, "%*g", d, v);
+#endif
+
 #include "cache/cache.h"
 
 #ifndef VRT_H_INCLUDED
@@ -13,12 +18,19 @@
 #endif
 
 void
-i2pl_free(void *obj)
+ip2l_free(VRT_CTX, void *obj)
 {
 	AN(obj);
+	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
 	IP2Location_close((IP2Location *)obj);
 }
 
+static const struct vmod_priv_methods ip2l_methods[1] = {{
+	.magic = VMOD_PRIV_METHODS_MAGIC,
+	.type = "vmod_std_ip2location",
+	.fini = ip2l_free
+}};
+
 VCL_VOID
 vmod_init_db(VRT_CTX, struct vmod_priv *priv, char *filename, char *memtype)
 {
@@ -51,7 +63,7 @@ vmod_init_db(VRT_CTX, struct vmod_priv *priv, char *fi
 	IP2Location_set_lookup_mode(IP2LocationObj, mtype);
 
 	priv->priv = IP2LocationObj;
-	priv->free = i2pl_free;
+	priv->methods = ip2l_methods;
 }
 
 static VCL_STRING
