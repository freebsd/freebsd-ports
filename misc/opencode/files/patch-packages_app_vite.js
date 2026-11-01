Disable Solid's template validation in the production web UI build.

babel-plugin-jsx-dom-expressions validates every generated template with
parse5 when config.validate is enabled.  On FreeBSD/aarch64 this
intermittently gets stuck in postprocess/isInvalidMarkup and the web UI build
spins indefinitely.  The validation only warns about malformed template HTML,
so disable it for the release build.

--- packages/app/vite.js.orig
+++ packages/app/vite.js
@@ -131,7 +131,7 @@
     },
   },
   ...tailwind,
-  solidPlugin(),
+  solidPlugin({ solid: { validate: false } }),
 ]
 
 export function inlineThemePreload(html) {
