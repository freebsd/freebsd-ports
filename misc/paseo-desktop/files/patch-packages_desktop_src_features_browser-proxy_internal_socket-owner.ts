Verify browser-proxy SOCKS5 client ownership on FreeBSD with sockstat(1):
libxo JSON on 15 and later, text on 14.  Upstream has no FreeBSD verifier
and fails closed, so the host browser proxy rejects every connection.

--- packages/desktop/src/features/browser-proxy/internal/socket-owner.ts.orig	2026-11-27 21:45:54 UTC
+++ packages/desktop/src/features/browser-proxy/internal/socket-owner.ts
@@ -4,6 +4,7 @@
   type ChildProcessWithoutNullStreams,
 } from "node:child_process";
 import { readFile as nodeReadFile } from "node:fs/promises";
+import { release as nodeRelease } from "node:os";
 import { promisify } from "node:util";
 
 const execFileAsync = promisify(nodeExecFile);
@@ -33,6 +34,7 @@
     options?: { timeout?: number; windowsHide?: boolean },
   ) => Promise<{ stdout: string }>;
   createWindowsWorker?: () => WindowsSocketOwnerWorker;
+  osRelease?: () => string;
 }
 
 const LINUX_LOOPBACK_IPV4_HEX = "0100007F";
@@ -136,6 +138,92 @@
   return null;
 }
 
+function isRecord(value: unknown): value is Record<string, unknown> {
+  return typeof value === "object" && value !== null && !Array.isArray(value);
+}
+
+/**
+ * FreeBSD 15 and later.  One entry per process holding the socket, `user`
+ * being its effective uid; entries with no visible holder have no `user`.
+ */
+export function isFreeBSDLoopbackSocketOwnedByJson(
+  sockstatJson: string,
+  clientPort: number,
+  serverPort: number,
+  expectedUid: number,
+): boolean {
+  if (!isValidPort(clientPort) || !isValidPort(serverPort)) {
+    return false;
+  }
+  try {
+    const parsed: unknown = JSON.parse(sockstatJson);
+    const sockstat = isRecord(parsed) ? parsed.sockstat : undefined;
+    const sockets = isRecord(sockstat) ? sockstat.socket : undefined;
+    if (!Array.isArray(sockets)) return false;
+    let matched = 0;
+    for (const entry of sockets) {
+      if (!isRecord(entry)) continue;
+      const local = isRecord(entry.local) ? entry.local : undefined;
+      const foreign = isRecord(entry.foreign) ? entry.foreign : undefined;
+      if (
+        local?.address !== "127.0.0.1" ||
+        local.port !== clientPort ||
+        foreign?.address !== "127.0.0.1" ||
+        foreign.port !== serverPort
+      ) {
+        continue;
+      }
+      if (entry.proto !== "tcp4" || typeof entry.user !== "number") return false;
+      if (entry.user !== expectedUid) return false;
+      matched += 1;
+    }
+    return matched > 0;
+  } catch {
+    return false;
+  }
+}
+
+/**
+ * FreeBSD 14, whose sockstat has no --libxo; remove once 14 is EoL.  The
+ * command name is printed verbatim, so a newline in it can forge a row.
+ * Any line that is not a complete row therefore denies: sockstat prints at
+ * most 10 characters of the name, too few for the leftover fragment to pass.
+ */
+export function isFreeBSDLoopbackSocketOwnedByText(
+  sockstatOutput: string,
+  clientPort: number,
+  serverPort: number,
+  expectedUid: number,
+): boolean {
+  if (!isValidPort(clientPort) || !isValidPort(serverPort)) {
+    return false;
+  }
+  const rowPattern =
+    /^(\d+|\?{1,2}) +(.*?) +(\d+|\?{1,2}) +(\d+|\?{1,2}) +tcp4 +(\d{1,3}(?:\.\d{1,3}){3}:\d+) +(\d{1,3}(?:\.\d{1,3}){3}:\d+) *$/u;
+  const expectedLocal = `127.0.0.1:${clientPort}`;
+  const expectedForeign = `127.0.0.1:${serverPort}`;
+  let matched = 0;
+  for (const line of sockstatOutput.split("\n")) {
+    if (line === "") continue;
+    // Bound the regex's backtracking; real rows are about 90 characters.
+    if (line.length > 256) return false;
+    const row = rowPattern.exec(line);
+    if (!row) return false;
+    if (row[5] !== expectedLocal || row[6] !== expectedForeign) continue;
+    if (row[1] !== String(expectedUid)) return false;
+    matched += 1;
+  }
+  return matched > 0;
+}
+
+// sockstat gained --libxo in FreeBSD 15.0; anything else gets the text path,
+// which 15 still supports.  The JSON path never falls back to text, so a 14
+// userland on a 15 kernel denies.
+export function freebsdSockstatSupportsLibxo(osRelease: string): boolean {
+  const major = /^(\d+)\./u.exec(osRelease)?.[1];
+  return major !== undefined && Number.parseInt(major, 10) >= 15;
+}
+
 export function parseWindowsLoopbackSocketOwner(output: string): string | null {
   const sid = output.trim();
   return /^S-1-\d+(?:-\d+)+$/u.test(sid) ? sid : null;
@@ -277,6 +365,8 @@
   deps: OsSocketOwnerVerifierDeps = {},
 ): SocketOwnerVerifier {
   const platform = deps.platform ?? process.platform;
+  const freebsdUseLibxo =
+    platform === "freebsd" && freebsdSockstatSupportsLibxo((deps.osRelease ?? nodeRelease)());
   const getCurrentUid =
     deps.getCurrentUid ?? (() => (typeof process.getuid === "function" ? process.getuid() : null));
   const readFile = deps.readFile ?? ((filePath, encoding) => nodeReadFile(filePath, encoding));
@@ -340,6 +430,29 @@
       }
     }
 
+    if (platform === "freebsd") {
+      const expectedUid = getCurrentUid();
+      if (expectedUid === null) return false;
+      try {
+        if (freebsdUseLibxo) {
+          const { stdout } = await execFile(
+            "/usr/bin/sockstat",
+            ["--libxo", "json", "-4", "-c", "-n", "-P", "tcp", "-p", String(clientPort)],
+            { timeout: LOOKUP_TIMEOUT_MS },
+          );
+          return isFreeBSDLoopbackSocketOwnedByJson(stdout, clientPort, serverPort, expectedUid);
+        }
+        const { stdout } = await execFile(
+          "/usr/bin/sockstat",
+          ["-4", "-c", "-n", "-q", "-P", "tcp", "-p", String(clientPort)],
+          { timeout: LOOKUP_TIMEOUT_MS },
+        );
+        return isFreeBSDLoopbackSocketOwnedByText(stdout, clientPort, serverPort, expectedUid);
+      } catch {
+        return false;
+      }
+    }
+
     if (platform === "win32") {
       try {
         return await getWindowsWorker().lookup({ clientPort, serverPort });
