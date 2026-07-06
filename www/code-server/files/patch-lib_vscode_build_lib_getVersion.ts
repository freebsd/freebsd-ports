--- lib/vscode/build/lib/getVersion.ts.orig
+++ lib/vscode/build/lib/getVersion.ts
@@ -8,7 +8,7 @@
 export function getVersion(root: string): string | undefined {
 	let version = process.env['BUILD_SOURCEVERSION'];
 
-	if (!version || !/^[0-9a-f]{40}$/i.test(version.trim())) {
+	if (!version || (!/^[0-9a-f]{40}$/i.test(version.trim()) && !/^[0-9]+(\.[0-9]+){1,3}$/i.test(version.trim()))) {
 		version = git.getVersion(root);
 	}
 
