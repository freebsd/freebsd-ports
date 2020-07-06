--- src/pdf/pdfcore.pro.orig	2020-03-16 14:04:24 UTC
+++ src/pdf/pdfcore.pro
@@ -32,13 +32,13 @@ for(object, NINJA_OBJECTS): RSP_CONTENT += $$object
 write_file($$RSP_FILE, RSP_CONTENT)
 
 macos:LIBS_PRIVATE += -Wl,-filelist,$$shell_quote($$RSP_FILE)
-linux:LIBS_PRIVATE += @$$RSP_FILE
+unix:LIBS_PRIVATE += @$$RSP_FILE
 
 # QTBUG-58710 add main rsp file on windows
 win32:QMAKE_LFLAGS += @$$RSP_FILE
 
 !isEmpty(NINJA_ARCHIVES) {
-    linux: LIBS_PRIVATE += -Wl,--start-group $$NINJA_ARCHIVES -Wl,--end-group
+    unix: LIBS_PRIVATE += -Wl,--start-group $$NINJA_ARCHIVES -Wl,--end-group
     else: LIBS_PRIVATE += $$NINJA_ARCHIVES
 }
 
