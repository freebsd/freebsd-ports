--- runLime.sh.orig	Mon Jun  9 22:45:57 2003
+++ runLime.sh	Wed Nov 26 15:30:04 2003
@@ -7,8 +7,10 @@
 # work around some limitations in the JDK1.3.  For more information
 # see http://java.sun.com/j2se/1.3/relnotes.html#vm
 #
-CLASSPATH=".:collections.jar:xerces.jar:jl011.jar:MessagesBundles.jar:themes.jar:logicrypto.jar:GURL.jar"
-export CLASSPATH
+CLASSPATH="%%JAR_DIR%%"
 J2SE_PREEMPTCLOSE=1
 export J2SE_PREEMPTCLOSE
-java -jar LimeWire.jar
+cd ${CLASSPATH}
+exec %%LOCALBASE%%/bin/javavm \
+	-cp "${CLASSPATH}/collections.jar:${CLASSPATH}/xerces.jar:${CLASSPATH}/jl011.jar:${CLASSPATH}/MessagesBundles.jar:${CLASSPATH}/themes.jar:${CLASSPATH}/logicrypto.jar:${CLASSPATH}/GURL.jar" \
+	-jar ${CLASSPATH}/LimeWire.jar
