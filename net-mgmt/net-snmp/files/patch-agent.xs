--- perl/agent/agent.xs.old	2006/09/01 21:05:50	5.15.2.3
+++ perl/agent/agent.xs	2007/01/06 00:35:12	5.15.2.4
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
 
