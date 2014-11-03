--- net/common/processors/service-proxy-proc.c.orig	2014-09-02 15:47:22.827928455 -0400
+++ net/common/processors/service-proxy-proc.c	2014-09-02 15:47:36.619949159 -0400
@@ -43,7 +43,7 @@
 {
     ServiceProxyPriv *priv = GET_PRIV(processor);
     if (priv->name) {
-        free (priv->name);
+        g_free (priv->name);
         priv->name = NULL;
     }
 
