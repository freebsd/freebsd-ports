--- lib/dns.js.orig	2015-02-13 23:42:28.000000000 +0800
+++ lib/dns.js	2015-02-13 23:46:39.000000000 +0800
@@ -125,6 +125,11 @@
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
