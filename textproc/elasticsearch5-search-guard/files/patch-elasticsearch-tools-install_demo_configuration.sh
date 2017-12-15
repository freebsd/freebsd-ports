--- elasticsearch/tools/install_demo_configuration.sh.orig	2017-09-15 11:37:44 UTC
+++ elasticsearch/tools/install_demo_configuration.sh
@@ -17,25 +17,14 @@ fi
 
 set -e
 BASE_DIR="$DIR/../../../"
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
-    ES_CONF_FILE="/etc/elasticsearch/elasticsearch.yml"
-    ES_BIN_DIR="/usr/share/elasticsearch/bin"
-    ES_PLUGINS_DIR="/usr/share/elasticsearch/plugins"
-    ES_LIB_PATH="/usr/share/elasticsearch/lib"
-    SUDO_CMD="sudo"
-    ES_INSTALL_TYPE="rpm/deb"
-    echo "This script maybe require your root password for 'sudo' privileges"
-fi
-
 if $SUDO_CMD test -f "$ES_CONF_FILE"; then
     :
 else
@@ -58,12 +47,8 @@ if [ ! -d $ES_LIB_PATH ]; then
 	exit -1
 fi
 
-if [ "$ES_INSTALL_TYPE" != "rpm/deb" ];then
-    ES_CONF_DIR=$(dirname "${ES_CONF_FILE}")
-    ES_CONF_DIR=`cd "$ES_CONF_DIR" ; pwd`
-else
-    ES_CONF_DIR="/etc/elasticsearch"    
-fi
+ES_CONF_DIR=$(dirname "${ES_CONF_FILE}")
+ES_CONF_DIR=`cd "$ES_CONF_DIR" ; pwd`
 
 ES_CONF_FILE="$ES_CONF_DIR/elasticsearch.yml"
 
@@ -123,7 +108,7 @@ ES_PLUGINS_DIR=`cd "$ES_PLUGINS_DIR" ; p
 echo "### Success"
 echo "### Execute this script now on all your nodes and then start all nodes"
 echo "### After the whole cluster is up execute: "
-echo "#!/bin/bash" | $SUDO_CMD tee sgadmin_demo.sh > /dev/null 
+echo "#!/usr/local/bin/bash" | $SUDO_CMD tee sgadmin_demo.sh > /dev/null 
 echo $SUDO_CMD "$ES_PLUGINS_DIR/search-guard-5/tools/sgadmin.sh" -cd "$ES_PLUGINS_DIR/search-guard-5/sgconfig" -cn searchguard_demo -ks "$ES_CONF_DIR/kirk.jks" -ts "$ES_CONF_DIR/truststore.jks" -nhnv | $SUDO_CMD tee -a sgadmin_demo.sh > /dev/null
 $SUDO_CMD chmod +x sgadmin_demo.sh
 $SUDO_CMD cat sgadmin_demo.sh | tail -1
