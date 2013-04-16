--- src/contribs-lib/CLucene/snowball/libstemmer/libstemmer.c.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/contribs-lib/CLucene/snowball/libstemmer/libstemmer.c	2013-03-29 18:54:39.000000000 -0400
@@ -35,9 +35,8 @@
 {
     stemmer_encoding enc;
     struct stemmer_modules * module;
-    struct sb_stemmer * stemmer =
-	    (struct sb_stemmer *) malloc(sizeof(struct sb_stemmer));
-    if (stemmer == NULL) return NULL;
+    struct sb_stemmer * stemmer;
+
     enc = sb_getenc(charenc);
     if (enc == ENC_UNKNOWN) return NULL;
 
@@ -46,6 +45,9 @@
     }
     if (module->name == NULL) return NULL;
     
+    stemmer = (struct sb_stemmer *) malloc(sizeof(struct sb_stemmer));
+    if (stemmer == NULL) return NULL;
+
     stemmer->create = module->create;
     stemmer->close = module->close;
     stemmer->stem = module->stem;
