--- libpb/mk.py
+++ libpb/mk.py
@@ -47,7 +47,7 @@ def load_defaults():
             "BATCH", "USE_PACKAGE_DEPENDS", "WITH_DEBUG", "WITH_PKGNG"
         ])
 
-    bsd_ports_mk = os.path.join(env.env["PORTSDIR"], "Mk", "bsd.ports.mk")
+    bsd_ports_mk = os.path.join(env.env["PORTSDIR"], "Mk", "bsd.port.mk")
     args = ["make", "-f", bsd_ports_mk] + ["-V%s" % i for i in keys]
     args += ["-D%s" % k if v is True else "%s=%s" % (k, v)
                                                   for k, v in env.env.items()]
