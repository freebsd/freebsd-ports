--- tests/unit_node/process_test.ts.orig	2026-07-01 13:28:43 UTC
+++ tests/unit_node/process_test.ts
@@ -695,7 +695,7 @@ Deno.test({
       listener.close();
     });
 
-    const shell = "/bin/bash";
+    const shell = "${PREFIX}/bin/bash";
     const cmd =
       `"${Deno.execPath()}" run ${scriptPath} < /dev/tcp/127.0.0.1/9000`;
     const args = ["-c", cmd];
