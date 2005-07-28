--- build.sh.orig	Wed Mar 23 12:44:13 2005
+++ build.sh	Wed Jul 27 18:50:50 2005
@@ -1,4 +1,4 @@
-#!/bin/sh
+#!/bin/sh -e
 
 #  Copyright 1999-2004 The Apache Software Foundation
 #
@@ -27,7 +27,7 @@
 
 # ----- Ignore system CLASSPATH variable
 OLD_CLASSPATH="$CLASSPATH"
-unset CLASSPATH
+unset CLASSPATH || true
 CLASSPATH="`echo lib/endorsed/*.jar | tr ' ' $S`"
 export CLASSPATH
 
