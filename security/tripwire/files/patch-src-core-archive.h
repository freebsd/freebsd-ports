--- src/core/archive.h.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/archive.h	2014-06-15 01:51:40.000000000 +0200
@@ -85,6 +85,8 @@ TSS_EXCEPTION( eArchiveStringTooLong, eA
 class cArchive
 {
 public:
+    virtual ~cArchive() {}
+
 	// convenience methods
     //
     // Specific Read functions throw(eArchive) if EOF is reached because
