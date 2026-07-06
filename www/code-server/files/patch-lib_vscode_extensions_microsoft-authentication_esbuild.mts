--- lib/vscode/extensions/microsoft-authentication/esbuild.mts.orig
+++ lib/vscode/extensions/microsoft-authentication/esbuild.mts
@@ -21,6 +21,7 @@
 	case 'win32': platformFolder = 'windows'; break;
 	case 'darwin': platformFolder = 'macos'; break;
 	case 'linux': platformFolder = 'linux'; break;
+	case 'freebsd': platformFolder = 'linux'; break;
 	default: throw new Error(`Unsupported platform: ${process.platform}`);
 }
 
