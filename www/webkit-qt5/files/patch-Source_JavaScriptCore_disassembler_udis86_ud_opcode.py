--- Source/JavaScriptCore/disassembler/udis86/ud_opcode.py.bak	2016-09-09 23:35:32.000000000 +1000
+++ Source/JavaScriptCore/disassembler/udis86/ud_opcode.py	2016-12-24 18:52:06.065571000 +1000
@@ -115,9 +115,9 @@
             '/mod'   : lambda v: '00' if v == '!11' else '01',
             # Mode extensions:
             # (16, 32, 64) => (00, 01, 02)
-            '/o'     : lambda v: "%02x" % (int(v) / 32),
-            '/a'     : lambda v: "%02x" % (int(v) / 32),
-            '/m'     : lambda v: "%02x" % (int(v) / 32),
+            '/o'     : lambda v: "%02x" % (int(v) // 32),
+            '/a'     : lambda v: "%02x" % (int(v) // 32),
+            '/m'     : lambda v: "%02x" % (int(v) // 32),
             '/sse'   : lambda v: UdOpcodeTables.OpcExtIndex['sse'][v]
         }
 
