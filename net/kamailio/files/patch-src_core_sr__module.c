--- src/core/sr_module.c.orig	(revision 43f764cae870b15a96b8ca88f1eb195d4ceb8455)
+++ src/core/sr_module.c
@@ -525,6 +525,7 @@
 	return -1;
 }
 
+
 /**
  * \brief load a sr module
  *
@@ -537,9 +538,10 @@
  * absolute path (not starting with '/') then will try:
  * \<MODS_DIR\>/mod_path
  * @param mod_path path or module name
+ * @param opts options string
  * @return 0 on success , <0 on error
  */
-int load_module(char* mod_path)
+int ksr_load_module(char* mod_path, char *opts)
 {
 	void* handle;
 	char* error;
@@ -553,11 +555,16 @@
 	str expref;
 	char exbuf[64];
 	char* mdir;
+	char *p;
 
 #ifndef RTLD_NOW
 /* for openbsd */
 #define RTLD_NOW DL_LAZY
 #endif
+#ifndef RTLD_GLOBAL
+/* Unsupported! */
+#define RTLD_GLOBAL 0
+#endif
 
 	if(ksr_locate_module(mod_path, &path)<0) {
 		return -1;
@@ -567,6 +574,17 @@
 
 	retries=2;
 	dlflags=RTLD_NOW;
+
+	if(opts!=NULL) {
+		for(p=opts; *p!='\0'; p++) {
+			if(*p=='G' || *p=='g') {
+				dlflags |= RTLD_GLOBAL;
+			} else {
+				LM_INFO("unknown option: %c\n", *p);
+			}
+		}
+	}
+
 reload:
 	handle=dlopen(path, dlflags); /* resolve all symbols now */
 	if (handle==0){
@@ -653,10 +671,11 @@
 	return -1;
 }
 
+
 /**
  *
  */
-int load_modulex(char* mod_path)
+int ksr_load_modulex(char* mod_path, char *opts)
 {
 	str seval;
 	str sfmt;
@@ -679,7 +698,7 @@
 		}
 	}
 
-	return load_module(emod);
+	return ksr_load_module(emod, opts);
 }
 
 /**
