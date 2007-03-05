--- perl/agent/agent.xs.old	Fri May 26 15:16:45 2006
+++ perl/agent/agent.xs	Mon Mar  5 13:42:35 2007
@@ -18,9 +18,9 @@
 } handler_cb_data;
 
 typedef struct netsnmp_oid_s {
-    unsigned int        *name;
-    unsigned int         len;
-    unsigned int         namebuf[ MAX_OID_LEN ];
+    oid                 *name;
+    size_t               len;
+    oid                  namebuf[ MAX_OID_LEN ];
 } netsnmp_oid;
 
 static int have_done_agent = 0;
@@ -569,7 +569,7 @@
         arg = newSVrv(rarg, "netsnmp_oidPtr");
         sv_setiv(arg, (IV) o);
 
-        XPUSHs(rarg);
+        XPUSHs(sv_2mortal(rarg));
 
         PUTBACK;
         i = perl_call_pv("NetSNMP::OID::newwithptr", G_SCALAR);
@@ -608,7 +608,7 @@
         arg = newSVrv(rarg, "netsnmp_oidPtr");
         sv_setiv(arg, (IV) o);
 
-        XPUSHs(rarg);
+        XPUSHs(sv_2mortal(rarg));
 
         PUTBACK;
         i = perl_call_pv("NetSNMP::OID::newwithptr", G_SCALAR);
@@ -997,11 +997,13 @@
                 rarg = newSViv(0);
                 arg = newSVrv(rarg, "NetSNMP::agent::netsnmp_request_infoPtr");
                 sv_setiv(arg, (IV) request);
-                ST(0) = rarg;
+                RETVAL = rarg;				
             } else {
-                ST(0) = &sv_undef;
+                RETVAL = &sv_undef;
             }
         }
+    OUTPUT:
+        RETVAL
 
 MODULE = NetSNMP::agent  PACKAGE = NetSNMP::agent::netsnmp_agent_request_info PREFIX = narqi_
 
