--- core/decoders/tight.js.orig	2020-07-14 08:16:52 UTC
+++ core/decoders/tight.js
@@ -56,7 +56,7 @@ export default class TightDecoder {
         } else if (this._ctl === 0x0A) {
             ret = this._pngRect(x, y, width, height,
                                 sock, display, depth);
-        } else if ((this._ctl & 0x80) == 0) {
+        } else if ((this._ctl & 0x08) == 0) {
             ret = this._basicRect(this._ctl, x, y, width, height,
                                   sock, display, depth);
         } else {
