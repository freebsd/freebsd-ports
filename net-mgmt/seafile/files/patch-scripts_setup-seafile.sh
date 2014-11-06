--- scripts/setup-seafile.sh.orig	2014-08-28 05:24:34.830623727 -0400
+++ scripts/setup-seafile.sh	2014-08-28 05:27:43.095059196 -0400
@@ -341,7 +341,7 @@
 }
 
 function copy_user_manuals() {
-    src_docs_dir=${INSTALLPATH}/seafile/docs/
+    src_docs_dir=${INSTALLPATH}/seafile/share/doc/seafile/
     library_template_dir=${seafile_data_dir}/library-template
     mkdir -p ${library_template_dir}
     cp -f ${src_docs_dir}/*.doc ${library_template_dir}
