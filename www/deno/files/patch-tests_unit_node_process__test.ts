--- tests/unit_node/process_test.ts.orig	2025-03-30 15:43:23 UTC
+++ tests/unit_node/process_test.ts
@@ -569,7 +569,7 @@ Deno.test({
       listener.close();
     });
 
-    const shell = "/bin/bash";
+    const shell = "${PREFIX}/bin/bash";
     const cmd =
       `"${Deno.execPath()}" run ${scriptPath} < /dev/tcp/127.0.0.1/9000`;
     const args = ["-c", cmd];
