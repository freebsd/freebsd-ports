--- src/rpsl/rpsl.l.orig	2012-07-31 12:10:39 UTC
+++ src/rpsl/rpsl.l
@@ -713,7 +713,7 @@ void handle_object_error(const char *s, 
    current_object->errors += buffer;
 }
 
-void rpslerror(const char *, ...) {
+void rpslerror(void *, const char *, ...) {
    if (current_attribute) {
       current_attribute->errorLine = errorLine;
       current_attribute->errorColon = errorColon - yyleng;
