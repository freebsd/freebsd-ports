--- lib/vscode/build/lib/copilot.ts.orig
+++ lib/vscode/build/lib/copilot.ts
@@ -377,6 +377,11 @@
 		return { dir: appRootDir, cleanup: noop };
 	}
 
+	const remoteDir = path.join(import.meta.dirname, '..', '..', 'remote', 'node_modules', '@github', `copilot-${copilotPackagePlatformArch}`);
+	if (readOptionalPackageVersion(remoteDir) === extVersion) {
+		return { dir: remoteDir, cleanup: noop };
+	}
+
 	const integrity = resolvePinnedPlatformPackageIntegrity(packageName, extVersion, options);
 	const staged = fs.mkdtempSync(path.join(os.tmpdir(), 'vscode-copilot-native-'));
 	try {
