--- lib/dns.js.orig	2015-03-31 22:13:01 UTC
+++ lib/dns.js
@@ -125,6 +125,11 @@ exports.lookup = function lookup(hostnam
         hints !== (exports.ADDRCONFIG | exports.V4MAPPED)) {
       throw new TypeError('invalid argument: hints must use valid flags');
     }
+    // FIXME(indutny): V4MAPPED on FreeBSD results in EAI_BADFLAGS, because
+    // the libc does not support it
+    if (process.platform === 'freebsd' && family !== 6) {
+      hints &= ~exports.V4MAPPED;
+    }
   } else {
     family = options >>> 0;
   }
