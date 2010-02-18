--- connection.c.orig	2007-07-31 09:03:53.000000000 +0200
+++ connection.c	2009-06-30 12:55:06.000000000 +0200
@@ -81,7 +81,7 @@
     Data_Get_Struct(self, conn_rec, conn);
     Check_Type(val, T_STRING);
     conn->user = ap_pstrndup(conn->pool,
-			     RSTRING(val)->ptr, RSTRING(val)->len);
+			     RSTRING_PTR(val), RSTRING_LEN(val));
     return val;
 }
 
@@ -92,7 +92,7 @@
     Data_Get_Struct(self, conn_rec, conn);
     Check_Type(val, T_STRING);
     conn->ap_auth_type = ap_pstrndup(conn->pool,
-				     RSTRING(val)->ptr, RSTRING(val)->len);
+				     RSTRING_PTR(val), RSTRING_LEN(val));
     return val;
 }
 #endif
