--- src/xml_elem.c.orig	2012-08-12 15:18:59 UTC
+++ src/xml_elem.c
@@ -186,7 +186,7 @@ static void
  * put @name into @data->array[@data->offset]
  */
 static void
-hash_key_put(void *payload, void *data, xmlChar *name)
+hash_key_put(void *payload, void *data, const xmlChar *name)
 {
     ArrayDest *dest = data;
     dest->array[dest->offset++] = name;
