--- install/install_apxs.sh.orig	2011-09-28 01:19:38.000000000 +0000
+++ install/install_apxs.sh	2011-09-29 14:24:06.000000000 +0000
@@ -84,7 +84,7 @@
   if [ ! -z "${APACHE_CONF_LINE}" ]; then
     local SED_REGEX="s/^.*${1}=?[\"\'\ ]*//"
     EXTRACTED_COMPILE_SETTING=$(echo "${APACHE_CONF_LINE}" |
-        sed -r "${SED_REGEX}" |
+        sed -E "${SED_REGEX}" |
         sed "s/[\"\'\ ]*$//")
   fi
 }
@@ -149,7 +149,7 @@
   APACHE_USER_LINE=$(egrep -i "^[[:blank:]]*User[[:blank:]]+" "${APACHE_CONF_FILE}")
   if [ ! -z "${APACHE_USER_LINE}" ]; then
     APACHE_USER=$(echo "${APACHE_USER_LINE}" |
-        sed -r s/^.*User[[:blank:]]+[\"\']*// |
+        sed -E s/^.*User[[:blank:]]+[\"\']*// |
         sed s/[\"\'[:blank:]]*$//)
   fi
 fi
@@ -159,7 +159,7 @@
   APACHE_GROUP_LINE=$(egrep -i "^[[:blank:]]*Group[[:blank:]]+" "${APACHE_CONF_FILE}")
   if [ ! -z "${APACHE_GROUP_LINE}" ]; then
     APACHE_GROUP=$(echo "${APACHE_GROUP_LINE}" |
-        sed -r s/^.*Group[[:blank:]]+[\"\']*// |
+        sed -E s/^.*Group[[:blank:]]+[\"\']*// |
         sed s/[\"\'[:blank:]]*$//)
   fi
 fi
@@ -180,11 +180,11 @@
 
 echo "mod_pagespeed needs to cache optimized resources on the file system."
 echo "The default location for this cache is '${MODPAGESPEED_CACHE_ROOT}'."
-read -p "Would you like to specify a different location? (y/N) " -n1 PROMPT
-if [ "${PROMPT}" = "y" -o "${PROMPT}" = "Y" ]; then
-  echo ""
-  read -p "Location for mod_pagespeed file cache: " MODPAGESPEED_CACHE_ROOT
-fi
+#read -p "Would you like to specify a different location? (y/N) " -n1 PROMPT
+#if [ "${PROMPT}" = "y" -o "${PROMPT}" = "Y" ]; then
+#  echo ""
+#  read -p "Location for mod_pagespeed file cache: " MODPAGESPEED_CACHE_ROOT
+#fi
 
 if [ -z "${MODPAGESPEED_CACHE_ROOT}" ]; then
   echo ""
