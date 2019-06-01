--- src/cmd/proto/proto.c.orig	2017-11-30 22:35:04 UTC
+++ src/cmd/proto/proto.c
@@ -396,6 +396,15 @@ proto(char* file, char* license, char* o
 
 #if !PROTO_STANDALONE
 #undef	error
+void
+error( int xit, const char *msg, ... )
+{
+	va_list ap;
+	va_start( ap, msg );
+	vfprintf( stderr, msg, ap );
+	va_end( ap );
+	exit( xit );
+}
 #endif
 
 typedef struct Sufcom_s
