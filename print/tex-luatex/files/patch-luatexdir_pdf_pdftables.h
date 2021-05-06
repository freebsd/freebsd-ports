--- luatexdir/pdf/pdftables.h.orig	2015-03-20 07:59:58 UTC
+++ luatexdir/pdf/pdftables.h
@@ -21,7 +21,7 @@
 #ifndef PDFTABLES_H
 #  define PDFTABLES_H
 
-const char *pdf_obj_typenames[PDF_OBJ_TYPE_MAX + 1];
+extern const char *pdf_obj_typenames[PDF_OBJ_TYPE_MAX + 1];
 
 typedef enum {
     union_type_int,
