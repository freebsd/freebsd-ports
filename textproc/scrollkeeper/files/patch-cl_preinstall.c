--- cl/src/preinstall.c	2001/07/14 10:49:05	1.15
+++ cl/src/preinstall.c	2002/06/02 04:25:51	1.16
@@ -65,7 +65,16 @@
     omf_new_name = argv[3];
 
     if (!update_doc_url_in_omf_file(omf_name, url, omf_new_name)) {
-    	fprintf(stderr, _("url update in OMF file %s failed\n"), omf_name);
+    	fprintf(stderr, _("Unable to update URL in OMF file %s.  Copying OMF file unchanged.\n"), omf_name);
+
+        /*
+         *  Copy the old file to the new name, since the missing file will
+	 *  break some packaging systems.  In these cases, it is better to
+	 *  at least get a package, even if a doc or two isn't registered
+	 *  properly than to not get a package built at all.
+         */
+	copy_file(omf_name, omf_new_name);
+
 	return 1;
     }
             
