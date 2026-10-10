--- node_modules/@modelcontextprotocol/inspector/node_modules/rolldown/dist/shared/binding-BY0qR5iS.mjs.orig	2026-10-09 14:24:07 UTC
+++ node_modules/@modelcontextprotocol/inspector/node_modules/rolldown/dist/shared/binding-BY0qR5iS.mjs
@@ -259,7 +259,11 @@ var require_binding = /* @__PURE__ */ __commonJSMin(((
 				} catch (e) {
 					loadErrors.push(e);
 				}
-			} else loadErrors.push(/* @__PURE__ */ new Error(`Unsupported architecture on FreeBSD: ${process.arch}`));
+			} else try {
+				return __require(`@rolldown/binding-freebsd-${process.arch}`);
+			} catch (e) {
+				loadErrors.push(e);
+			}
 		} else if (process.platform === "linux") {
 			if (process.arch === "x64") {
 				if (isMusl()) {
