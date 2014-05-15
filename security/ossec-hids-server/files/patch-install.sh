--- ./install.sh.orig	2013-10-29 12:13:44.000000000 -0600
+++ ./install.sh	2014-04-21 19:52:35.000000000 -0600
@@ -67,9 +67,6 @@
 	echo "5- ${installing}"
 
 	echo "DIR=\"${INSTALLDIR}\"" > ${LOCATION}
-    echo "CC=${CC}" >> ${LOCATION}
-    echo "GCC=${CC}" >> ${LOCATION}
-    echo "CLANG=clang" >> ${LOCATION}
 
     # Changing Config.OS with the new C flags
     # Checking if debug is enabled
@@ -811,19 +808,6 @@
         export  PATH
     fi
 
-    ls "`which gcc`" > /dev/null 2>&1
-    if [ ! $? = 0 ]; then
-        ls "`which cc`" > /dev/null 2>&1
-        if [ ! $? = 0 ]; then
-            if [ "X${USER_BINARYINSTALL}" = "X" ]; then
-                catError "0x3-dependencies"
-            fi
-        fi
-        CC="cc"
-    else
-        CC="gcc"
-    fi
-
     PATH=$OLDOPATH
     export PATH
 }
