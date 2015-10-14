--- lib/x509v3ext.cpp.orig	2012-05-12 09:37:14 UTC
+++ lib/x509v3ext.cpp
@@ -27,6 +27,8 @@ x509v3ext::x509v3ext(const X509_EXTENSIO
 x509v3ext::x509v3ext(const x509v3ext &n)
 {
 	ext = NULL;
+	if (!n.isValid())
+		return;
 	set(n.ext);
 }
 
@@ -743,7 +745,7 @@ X509_EXTENSION *x509v3ext::get() const
 
 bool x509v3ext::isValid() const
 {
-	return ext->value->length > 0 &&
+	return ext && ext->value && ext->value->length > 0 &&
 		OBJ_obj2nid(ext->object) != NID_undef;
 }
 
