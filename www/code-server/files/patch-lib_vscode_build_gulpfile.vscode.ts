--- lib/vscode/build/gulpfile.vscode.ts.orig
+++ lib/vscode/build/gulpfile.vscode.ts
@@ -188,11 +188,11 @@
 	compileExtensionMediaBuildTask,
 	writeISODate('out-build'),
 	// Type-check with tsgo (no emit)
-	task.define('tsgo-typecheck', () => spawnTsgo(path.join(root, 'src', 'tsconfig.json'), { taskName: 'tsgo-typecheck', noEmit: true })),
+	task.define('tsgo-typecheck', () => process.platform === 'freebsd' ? Promise.resolve() : spawnTsgo(path.join(root, 'src', 'tsconfig.json'), { taskName: 'tsgo-typecheck', noEmit: true })),
 	// Transpile individual files to out-build first (for unit tests)
 	task.define('esbuild-out-build', () => runEsbuildTranspile('out-build', false)),
 	// Then bundle for shipping (bundles also write NLS files to out-build)
-	task.parallel(
+	(process.platform === 'freebsd' ? task.series : task.parallel)(
 		task.define('esbuild-vscode-min', () => runEsbuildBundle('out-vscode-min', true, true, 'desktop', `${sourceMappingURLBase}/core`)),
 		task.define('esbuild-vscode-reh-min', () => runEsbuildBundle('out-vscode-reh-min', true, true, 'server', `${sourceMappingURLBase}/core`)),
 		task.define('esbuild-vscode-reh-web-min', () => runEsbuildBundle('out-vscode-reh-web-min', true, true, 'server-web', `${sourceMappingURLBase}/core`)),
