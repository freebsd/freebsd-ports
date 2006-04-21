
$FreeBSD$

--- modules/usrloc/urecord.c
+++ modules/usrloc/urecord.c
@@ -502,8 +502,8 @@
 	
 	ptr = _r->contacts;
 	while(ptr) {
-		if ((_c->len == ptr->c.len) &&
-		    !memcmp(_c->s, ptr->c.s, _c->len)) {
+		if (_c == NULL || ((_c->len == ptr->c.len) &&
+		    !memcmp(_c->s, ptr->c.s, _c->len))) {
 			*_co = ptr;
 			return 0;
 		}
