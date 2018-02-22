--- libresapi/src/libresapi.pro.orig	2017-10-20 20:57:46 UTC
+++ libresapi/src/libresapi.pro	
@@ -160,9 +160,20 @@
 		api/ApiServerMHD.h
 }

+freebsd-clang {
+	JSON_SOURCES = api/json.cpp
+	json.name = json
+	json.input = JSON_SOURCES
+	json.variable_out = OBJECTS
+	json.dependency_type = TYPE_C
+	json.output = ${QMAKE_VAR_OBJECTS_DIR}${QMAKE_FILE_IN_BASE}$${first(QMAKE_EXT_OBJ)}
+	json.commands = $${QMAKE_CXX} $(CXXFLAGS) -std=gnu++98 $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
+	QMAKE_EXTRA_COMPILERS += json
+}
+
+
 SOURCES += \
 	api/ApiServer.cpp \
-	api/json.cpp \
 	api/JsonStream.cpp \
 	api/ResourceRouter.cpp \
 	api/PeersHandler.cpp \

