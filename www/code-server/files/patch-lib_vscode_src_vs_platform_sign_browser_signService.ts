--- lib/vscode/src/vs/platform/sign/browser/signService.ts.orig
+++ lib/vscode/src/vs/platform/sign/browser/signService.ts
@@ -42,18 +42,11 @@
 		super();
 	}
 	protected override getValidator(): Promise<IVsdaValidator> {
-		return this.vsda().then(vsda => {
-			const v = new vsda.validator();
-			return {
-				createNewMessage: arg => v.createNewMessage(arg),
-				validate: arg => v.validate(arg),
-				dispose: () => v.free(),
-			};
-		});
+		return Promise.reject(new Error("VSDA is not available"));
 	}
 
 	protected override signValue(arg: string): Promise<string> {
-		return this.vsda().then(vsda => vsda.sign(arg));
+		return Promise.reject(new Error("VSDA is not available"));
 	}
 
 	@memoize
