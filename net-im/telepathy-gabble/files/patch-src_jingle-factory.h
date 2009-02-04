--- src/jingle-factory.h.orig	2009-02-04 15:04:34.000000000 -0500
+++ src/jingle-factory.h	2009-02-04 15:06:02.000000000 -0500
@@ -94,6 +94,11 @@ typedef enum {
 } JingleCandidateType;
 
 typedef struct _GabbleJingleFactoryClass GabbleJingleFactoryClass;
+typedef struct _GabbleJingleFactoryHashType GabbleJingleFactoryHashType;
+
+struct _GabbleJingleFactoryHashType {
+  GType type;
+};
 
 GType gabble_jingle_factory_get_type (void);
 
