--- scripts/setup-seafile.sh.orig	2016-10-21 22:12:15 UTC
+++ scripts/setup-seafile.sh
@@ -318,7 +318,11 @@ fi
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
