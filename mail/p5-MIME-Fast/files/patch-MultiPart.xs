--- Fast/MultiPart.xs.orig	2004-12-09 19:33:21.796875000 +0300
+++ Fast/MultiPart.xs	2004-12-09 19:33:31.859375000 +0300
@@ -67,7 +67,7 @@
 	int			index;
     CODE:
 	if (sv_isobject(subpart) && SvROK(subpart)) {
-	  IV tmp = SvIV((SV*)SvRV(ST(0)));
+	  IV tmp = SvIV((SV*)SvRV(subpart));
 	  mime_object = INT2PTR(MIME__Fast__Object, tmp);
           if (gmime_debug)
             warn("g_mime_part_remove_subpart: 0x%x, child=0x%x (not add to plist)", mime_multipart, mime_object);
@@ -224,7 +224,7 @@
 	GMimeObject		*mime_object;
     CODE:
 	if (sv_isobject(subpart) && SvROK(subpart)) {
-	  IV tmp = SvIV((SV*)SvRV(ST(0)));
+	  IV tmp = SvIV((SV*)SvRV(subpart));
 	  mime_object = INT2PTR(MIME__Fast__Object, tmp);
           g_mime_multipart_add_part(mime_multipart, mime_object);
           plist = g_list_remove(plist, subpart);
@@ -237,7 +237,7 @@
 	GMimeObject		*mime_object;
     CODE:
 	if (sv_isobject(subpart) && SvROK(subpart)) {
-	  IV tmp = SvIV((SV*)SvRV(ST(0)));
+	  IV tmp = SvIV((SV*)SvRV(subpart));
 	  mime_object = INT2PTR(MIME__Fast__Object, tmp);
           g_mime_multipart_add_part_at(mime_multipart, mime_object, index);
           plist = g_list_remove(plist, subpart);
