--- plugins/scimlauncher/scimlauncher.cpp~	Sun Jul 11 06:19:13 2004
+++ plugins/scimlauncher/scimlauncher.cpp	Wed Jul 21 15:32:13 2004
@@ -31,6 +31,20 @@
 K_EXPORT_COMPONENT_FACTORY( skimplugin_scim,
                               KGenericFactory<ScimLauncher>( "skimplugin_scim" ) );
 
+char* mystrndup (const char* s, size_t n){
+	size_t len=strlen(s);
+	if(len>n)
+		len=n;
+	char* newc=(char*)malloc(len+1);
+
+	if (newc==NULL)
+		return NULL;
+
+	newc[len] = '\0';
+	return (char *)memcpy(newc, s, len);
+}
+#define strndup mystrndup
+
 ScimThread::ScimThread(QString _args)
 {
     args = "skim " + _args;
