--- lib/Widgets/ContractorView.vala.orig	2016-08-06 23:51:23 UTC
+++ lib/Widgets/ContractorView.vala
@@ -181,7 +181,11 @@ public class Granite.Widgets.ContractorView : TreeView
 	        string text = value.get_string ();
 
 	        if (text[3:text.index_of ("</b>")] in names) {
+#if VALA_0_36
+	            list.remove (ref it);
+#else
 	            list.remove (it);
+#endif
 	            blacklisted_pos += cur_pos;
             }
 	        if (!check)
