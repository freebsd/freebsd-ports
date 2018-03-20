--- elasticsearch/tools/install_demo_configuration.sh.orig	2018-03-20 16:29:13 UTC
+++ elasticsearch/tools/install_demo_configuration.sh
@@ -26,34 +26,14 @@ if [ -d "$BASE_DIR" ]; then
 else
     echo "DEBUG: basedir does not exist"
 fi
-ES_CONF_FILE="$BASE_DIR/config/elasticsearch.yml"
+ES_CONF_FILE="%%PREFIX%%/etc/elasticsearch/elasticsearch.yml"
 ES_BIN_DIR="$BASE_DIR/bin"
 ES_PLUGINS_DIR="$BASE_DIR/plugins"
 ES_LIB_PATH="$BASE_DIR/lib"
 SUDO_CMD=""
-BASE_64_DECODE_CMD="base64 -d"
+BASE_64_DECODE_CMD="b64decode -m -p -r"
 ES_INSTALL_TYPE=".tar.gz"
 
-#Check if its a rpm/deb install
-if [ -f /usr/share/elasticsearch/bin/elasticsearch ]; then
-    ES_CONF_FILE="/usr/share/elasticsearch/config/elasticsearch.yml"
-
-    if [ ! -f "$ES_CONF_FILE" ]; then
-        ES_CONF_FILE="/etc/elasticsearch/elasticsearch.yml"
-    fi
-
-    ES_BIN_DIR="/usr/share/elasticsearch/bin"
-    ES_PLUGINS_DIR="/usr/share/elasticsearch/plugins"
-    ES_LIB_PATH="/usr/share/elasticsearch/lib"
-
-    if [ -x "$(command -v sudo)" ]; then
-        SUDO_CMD="sudo"
-        echo "This script maybe require your root password for 'sudo' privileges"
-    fi
-
-    ES_INSTALL_TYPE="rpm/deb"
-fi
-
 if [ $SUDO_CMD ]; then
     if ! [ -x "$(command -v $SUDO_CMD)" ]; then
         echo "Unable to locate 'sudo' command. Quit."
@@ -168,10 +148,10 @@ ES_PLUGINS_DIR=`cd "$ES_PLUGINS_DIR" ; p
 echo "### Success"
 echo "### Execute this script now on all your nodes and then start all nodes"
 echo "### After the whole cluster is up execute: "
-echo "#!/bin/bash" | $SUDO_CMD tee sgadmin_demo.sh > /dev/null 
+echo "%%BASH%%" | $SUDO_CMD tee sgadmin_demo.sh > /dev/null 
 echo $SUDO_CMD "$ES_PLUGINS_DIR/search-guard-5/tools/sgadmin.sh" -cd "$ES_PLUGINS_DIR/search-guard-5/sgconfig" -icl -ks "$ES_CONF_DIR/kirk.jks" -ts "$ES_CONF_DIR/truststore.jks" -nhnv | $SUDO_CMD tee -a sgadmin_demo.sh > /dev/null
 $SUDO_CMD chmod +x sgadmin_demo.sh
 $SUDO_CMD cat sgadmin_demo.sh | tail -1
 echo "### or run ./sgadmin_demo.sh"
 echo "### Then open https://localhost:9200 an login with admin/admin"
-echo "### (Just ignore the ssl certificate warning because we installed a self signed demo certificate)"
\ No newline at end of file
+echo "### (Just ignore the ssl certificate warning because we installed a self signed demo certificate)"
