--- web/javascript/transmission.js.orig
+++ web/javascript/transmission.js
@@ -1248,4 +1248,5 @@
                                 args.url = '/transmission/upload?paused=' + (this[Prefs._AutoStart] ? 'false' : 'true');
                                 args.type = 'POST';
+                                args.data = { 'X-Transmission-Session-Id' : tr.remote._token };
                                 args.dataType = 'xml';
                                 args.iframe = true;
