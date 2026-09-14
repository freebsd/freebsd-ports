--- frontend/apps/remark42/app/utils/set-dom-props.ts.orig	2026-09-14 00:23:44 UTC
+++ frontend/apps/remark42/app/utils/set-dom-props.ts
@@ -12,7 +12,7 @@ export function setStyles(element: HTMLElement, styles
   const entr = Object.entries(styles);
 
   entr.forEach(([p, v]) => {
-    element.style[p as keyof StylesDeclaration] = `${v}`;
+    (element.style[p as any] as string) = `${v}`;
   });
 }
 
