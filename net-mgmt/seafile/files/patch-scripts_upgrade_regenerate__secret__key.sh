--- scripts/upgrade/regenerate_secret_key.sh.orig	2016-01-29 17:25:05 UTC
+++ scripts/upgrade/regenerate_secret_key.sh
@@ -10,4 +10,6 @@ seahub_settings_py=${TOPDIR}/seahub_sett
 
 line="SECRET_KEY = \"$(python $seahub_secret_keygen)\""
 
-sed -i -e "/SECRET_KEY/c\\$line" $seahub_settings_py
+sed -i.bak -e "/SECRET_KEY/c\\
+$line
+" $seahub_settings_py
