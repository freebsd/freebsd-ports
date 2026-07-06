--- lib/vscode/build/lib/extensions.ts.orig
+++ lib/vscode/build/lib/extensions.ts
@@ -89,7 +89,7 @@
 			? es.merge(
 				fromLocalEsbuild(extensionPath, esbuildConfigFileName),
 				// Standard esbuild extensions need a separate type check step
-				...getBuildRootsForExtension(extensionPath).map(root => typeCheckExtensionStream(root, forWeb)),
+				...(process.platform === 'freebsd' ? [] : getBuildRootsForExtension(extensionPath).map(root => typeCheckExtensionStream(root, forWeb))),
 			)
 			// Extensions with their own build system (e.g. .esbuild.mts) handle type checking internally
 			: fromLocalEsbuild(extensionPath, esbuildConfigFileName);
@@ -745,7 +745,7 @@
 		outputRoot: outputRoot ? path.join(root, outputRoot, path.dirname(script)) : undefined
 	})));
 
-	const typeCheckTasks = esbuildMediaScripts.map(({ tsconfig }) => {
+	const typeCheckTasks = process.platform === 'freebsd' ? [] : esbuildMediaScripts.map(({ tsconfig }) => {
 		const tsconfigPath = path.join(extensionsPath, tsconfig);
 		const config = { taskName: 'typechecking extension media (tsgo)', noEmit: true };
 		if (!isWatch) {
