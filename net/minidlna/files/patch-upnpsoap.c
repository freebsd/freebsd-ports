--- upnpsoap.c~	2014-05-26 15:54:53.125084054 +0200
+++ upnpsoap.c	2014-05-26 15:56:21.415094729 +0200
@@ -1300,7 +1300,7 @@
 	free(str.data);
 }
 
-inline void
+static inline void
 charcat(struct string_s *str, char c)
 {
 	if (str->size <= str->off)
