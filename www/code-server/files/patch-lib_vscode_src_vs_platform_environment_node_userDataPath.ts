--- lib/vscode/src/vs/platform/environment/node/userDataPath.ts.orig
+++ lib/vscode/src/vs/platform/environment/node/userDataPath.ts
@@ -96,6 +96,7 @@
 			appDataPath = join(homedir(), 'Library', 'Application Support');
 			break;
 		case 'linux':
+		case 'freebsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || join(homedir(), '.config');
 			break;
 		default:
