$FreeBSD$

--- cocoon.sh.orig	Thu Feb 12 09:48:55 2004
+++ cocoon.sh	Tue May  4 14:44:24 2004
@@ -57,8 +57,7 @@
 # ----- Verify and Set Required Environment Variables -------------------------
 
 if [ "$JAVA_HOME" = "" ] ; then
-  echo You must set JAVA_HOME to point at your Java Development Kit installation
-  exit 1
+  JAVA_HOME="%%JAVA_HOME%%"
 fi
 
 if [ "$JAVA_OPTIONS" = "" ] ; then
@@ -66,7 +65,7 @@
 fi
 
 if [ "$COCOON_HOME" = "" ] ; then
-  COCOON_HOME='.'
+  COCOON_HOME="%%APP_HOME%%"
 fi
 
 if [ "$COCOON_WEBAPP_HOME" = "" ] ; then
@@ -76,7 +75,7 @@
     COCOON_WEBAPP_HOME=$STANDALONE_WEBAPP
   else
     # when in the build environment
-    COCOON_WEBAPP_HOME="$COCOON_HOME/build/webapp"
+    COCOON_WEBAPP_HOME="$COCOON_HOME/webapp"
   fi
 fi
 echo "$0: using $COCOON_WEBAPP_HOME as the webapp directory"
@@ -111,7 +110,7 @@
 
 # ----- Set Local Variables ( used to minimize cut/paste) ---------------------
 
-JAVA="$JAVA_HOME/bin/java"
+JAVA="exec $JAVA_HOME/bin/java"
 ENDORSED_LIBS="$COCOON_HOME/lib/endorsed"
 ENDORSED="-Djava.endorsed.dirs=$ENDORSED_LIBS"
 PARSER=-Dorg.xml.sax.parser=org.apache.xerces.parsers.SAXParser
