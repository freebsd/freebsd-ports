--- scripts/setup-seafile.sh.orig	2015-01-28 00:37:17.000000000 -0500
+++ scripts/setup-seafile.sh	2015-01-28 00:43:26.000000000 -0500
@@ -339,7 +339,11 @@
 }
 
 function copy_user_manuals() {
-    src_docs_dir=${INSTALLPATH}/seafile/docs/
+    if [ $(uname | grep -e BSD -e DragonFly | wc -l) == "1" ]; then
+        src_docs_dir=${INSTALLPATH}/seafile/share/doc/seafile/
+    else
+    	src_docs_dir=${INSTALLPATH}/seafile/docs/
+    fi
     library_template_dir=${seafile_data_dir}/library-template
     mkdir -p ${library_template_dir}
     cp -f ${src_docs_dir}/*.doc ${library_template_dir}
