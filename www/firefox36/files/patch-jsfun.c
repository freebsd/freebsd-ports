--- js/src/jsfun.c.orig	Fri May 30 20:55:38 2003
+++ js/src/jsfun.c	Fri May 30 20:54:24 2003
@@ -1081,7 +1081,7 @@
     JSString *atomstr;
     char *propname;
     JSScopeProperty *sprop;
-    jsid userid;
+    uint32 userid;
     JSAtom *atom;
     uintN i, n, dupflag;
     uint32 type;
@@ -1157,7 +1157,7 @@
                 userid = INT_TO_JSVAL(sprop->shortid);
                 propname = ATOM_BYTES((JSAtom *)sprop->id);
                 if (!JS_XDRUint32(xdr, &type) ||
-                    !JS_XDRUint32(xdr, (uint32 *)&userid) ||
+                    !JS_XDRUint32(xdr, &userid) ||
                     !JS_XDRCString(xdr, &propname)) {
                     if (mark)
                         JS_ARENA_RELEASE(&cx->tempPool, mark);
@@ -1173,7 +1173,7 @@
                 uintN attrs = JSPROP_ENUMERATE | JSPROP_PERMANENT;
 
                 if (!JS_XDRUint32(xdr, &type) ||
-                    !JS_XDRUint32(xdr, (uint32 *)&userid) ||
+                    !JS_XDRUint32(xdr, &userid) ||
                     !JS_XDRCString(xdr, &propname)) {
                     return JS_FALSE;
                 }
