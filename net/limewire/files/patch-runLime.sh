--- runLime.sh.orig	Thu Mar 14 14:00:50 2002
+++ runLime.sh	Thu Jul 11 17:07:02 2002
@@ -7,8 +7,9 @@
 # work around some limitations in the JDK1.3.  For more information
 # see http://java.sun.com/j2se/1.3/relnotes.html#vm
 #
-CLASSPATH=".:collections.jar:xerces.jar:jl011.jar"
-export CLASSPATH
+CLASSPATH="%%JAR_DIR%%"
 J2SE_PREEMPTCLOSE=1
 export J2SE_PREEMPTCLOSE
-java -jar RunLime.jar
+exec %%LOCALBASE%%/bin/javavm \
+	-cp ${CLASSPATH}/collections.jar:${CLASSPATH}/xerces.jar:${CLASSPATH}/jl011.jar \
+	-jar ${CLASSPATH}/LimeWire.jar
