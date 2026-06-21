--- lib/vscode/build/gulpfile.extensions.ts.orig
+++ lib/vscode/build/gulpfile.extensions.ts
@@ -264,7 +264,7 @@
 /**
  * brings in the marketplace extensions for the build
  */
-const bundleMarketplaceExtensionsBuildTask = task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build')));
+const bundleMarketplaceExtensionsBuildTask = task.define('bundle-marketplace-extensions-build', () => process.platform === 'freebsd' ? es.readArray([]) : ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build')));
 
 /**
  * Compiles the non-native extensions for the build
