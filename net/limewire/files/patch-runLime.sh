--- runLime.sh.orig	Wed May 15 14:32:03 2002
+++ runLime.sh	Tue Jul 16 22:25:34 2002
@@ -7,8 +7,9 @@
 # work around some limitations in the JDK1.3.  For more information
 # see http://java.sun.com/j2se/1.3/relnotes.html#vm
 #
-CLASSPATH=".:collections.jar:xerces.jar:jl011.jar:MessagesBundles.jar"
-export CLASSPATH
+CLASSPATH="%%JAR_DIR%%"
 J2SE_PREEMPTCLOSE=1
 export J2SE_PREEMPTCLOSE
-java -jar RunLime.jar
+exec %%LOCALBASE%%/bin/javavm \
+	-cp "${CLASSPATH}/collections.jar:${CLASSPATH}/xerces.jar:${CLASSPATH}/jl011.jar:${CLASSPATH}/MessagesBundles.jar" \
+	-jar ${CLASSPATH}/LimeWire.jar
