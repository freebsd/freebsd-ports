--- extensions/adblock/widgets.vala.orig	2015-08-30 11:56:26 UTC
+++ extensions/adblock/widgets.vala
@@ -227,7 +227,11 @@ namespace Adblock {
                             liststore.get (iter, 0, out sub);
                             if (sub.mutable) {
                                 config.remove (sub);
+#if VALA_0_36
+                                liststore.remove (ref iter);
+#else
                                 liststore.remove (iter);
+#endif
                                 return true;
                             }
                         }
