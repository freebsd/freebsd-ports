$FreeBSD$

--- buildjs.sh.orig	2011-02-08 08:07:00.000000000 -0800
+++ buildjs.sh	2011-03-03 15:58:08.000000000 -0800
@@ -14,7 +14,7 @@
     exit $2
 }
 
-JAVA_CHECK=`java -version 2>&1 | grep "java version \"1.[6-9]"`
+JAVA_CHECK=`java -version 2>&1 | grep "version \"1.[6-9]"`
 if [ -z "$JAVA_CHECK" ]; then
     which java
     do_exit "This script requires the Sun JDK 1.6 or greater." $MISSING_JDK_1_6
@@ -30,16 +30,6 @@
     if [ ! -d ./jsbuildertmp ]; then
         mkdir jsbuildertmp || do_exit 'Unable to make temp directory. No permission?' $CANNOT_MAKE_TEMP_DIR
     fi
-    WGET_COMMAND=`which wget`
-    if [ -z "$WGET_COMMAND" ]; then
-        CURL_COMMAND=`which curl`
-        if [ -z "$CURL_COMMAND" ]; then
-            do_exit 'wget or curl required for buildjs.sh' $MISSING_WGET_AND_CURL
-        fi
-        curl -L http://www.extjs.com/deploy/JSBuilder2.zip -o ./jsbuildertmp/JSBuilder2.zip
-    else
-        wget -O ./jsbuildertmp/JSBuilder2.zip http://www.extjs.com/deploy/JSBuilder2.zip
-    fi
     UNZIP=`which unzip`
     if [ -z "$UNZIP" ]; then
         do_exit "Unzip not available to unzip JSBuilder2.zip" $MISSING_UNZIP
