--- golded3/geinit.cpp.orig	Sun May 14 18:09:02 2006
+++ golded3/geinit.cpp	Wed Nov  1 02:49:10 2006
@@ -413,19 +413,22 @@
   wcenters(12, C_BRAGW, "redistribute the program or any parts hereof under cer-");
   wcenters(13, C_BRAGW, "tain conditions. See the LICENSE.TXT for more details.");
 
-  wcenters(MAXROW-10, C_BRAGW, "This executable is distributed by");
-  if (*__gver_vendor_fido__)
+  if (*__gver_vendor_name__)
   {
-    gsprintf(PRINTF_DECLARE_BUFFER(buf), "%s (Fido: %s) - <%s>",
-      __gver_vendor_name__, __gver_vendor_fido__, __gver_vendor_email__);
+    wcenters(MAXROW-10, C_BRAGW, "This executable is distributed by");
+    if (*__gver_vendor_fido__)
+    {
+	gsprintf(PRINTF_DECLARE_BUFFER(buf), "%s (Fido: %s) - <%s>",
+        __gver_vendor_name__, __gver_vendor_fido__, __gver_vendor_email__);
+    }
+    else
+    {
+	gsprintf(PRINTF_DECLARE_BUFFER(buf), "%s <%s>",
+         __gver_vendor_name__, __gver_vendor_email__);
+    }
+  
+    wcenters(MAXROW-9, C_BRAGW, buf);
   }
-  else
-  {
-    gsprintf(PRINTF_DECLARE_BUFFER(buf), "%s <%s>",
-      __gver_vendor_name__, __gver_vendor_email__);
-  }
-
-  wcenters(MAXROW-9, C_BRAGW, buf);
   gsprintf(PRINTF_DECLARE_BUFFER(buf), "Compiled on %s %s", __gver_date__, __gver_time__);
   wcenters(MAXROW-8, C_BRAGW, buf);
 }
