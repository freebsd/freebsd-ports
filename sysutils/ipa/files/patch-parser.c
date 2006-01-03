--- src/parser.c.orig	Sat Dec  3 11:28:00 2005
+++ src/parser.c	Tue Jan  3 13:44:50 2006
@@ -533,7 +533,7 @@
  * outside of this function.
  */
 struct parser_pbuf *
-parser_new_pbuf(u_int size)
+parser_new_pbuf(size_t size)
 {
 	struct parser_pbuf *pbuf;
 
