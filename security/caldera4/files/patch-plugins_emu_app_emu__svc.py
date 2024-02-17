--- plugins/emu/app/emu_svc.py.orig	2022-06-12 20:12:01 UTC
+++ plugins/emu/app/emu_svc.py
@@ -12,7 +12,7 @@
 
 
 class EmuService(BaseService):
-    _dynamicically_compiled_payloads = {'sandcat.go-linux', 'sandcat.go-darwin', 'sandcat.go-windows'}
+    _dynamicically_compiled_payloads = {'sandcat.go-linux', 'sandcat.go-darwin', 'sandcat.go-windows', 'sandcat.go-freebsd'}
     _emu_config_path = "conf/default.yml"
 
     def __init__(self):
