--- ppl/unix/ppldns.c.orig	Mon Sep 29 00:20:45 2003
+++ ppl/unix/ppldns.c	Fri Nov  7 13:10:55 2003
@@ -295,40 +295,40 @@
 
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) ||\
-    defined(OLD_NAMESER) || defined(__FreeBSD__)
+    defined(OLD_NAMESER)
       type = _get_short (cp);
       cp += sizeof (u_short);
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__FreeBSD__)
       GETSHORT(type, cp);
 #else
       NS_GET16 (type, cp);
 #endif
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) ||\
-    defined(OLD_NAMESER) || defined(__FreeBSD__)
+    defined(OLD_NAMESER)
       aclass = _get_short (cp);
       cp += sizeof (u_short);
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__FreeBSD__)
       GETSHORT(aclass, cp);
 #else
       NS_GET16 (aclass, cp);
 #endif
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) ||\
-    defined(OLD_NAMESER) || defined(__FreeBSD__)
+    defined(OLD_NAMESER)
       ttl = _get_long (cp);
       cp += sizeof (u_long);
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__FreeBSD__)
       GETLONG(ttl, cp);
 #else
       NS_GET32 (ttl, cp);
 #endif
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) ||\
-    defined(OLD_NAMESER) || defined(__FreeBSD__)
+    defined(OLD_NAMESER)
       dlen = _get_short (cp);
       cp += sizeof (u_short);
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__FreeBSD__)
       GETSHORT(dlen, cp);
 #else
       NS_GET16 (dlen, cp);
@@ -340,30 +340,30 @@
 	  continue;
 	}
 #if defined(__NetBSD__) || defined(__OpenBSD__) ||\
-    defined(OLD_NAMESER) || defined(__FreeBSD__)
+    defined(OLD_NAMESER)
       pref = _get_short (cp);
       cp += sizeof (u_short);
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__FreeBSD__)
       GETSHORT(pref, cp);
 #else
       NS_GET16 (pref, cp);
 #endif
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) ||\
-    defined(OLD_NAMESER) || defined(__FreeBSD__)
+    defined(OLD_NAMESER)
       weight = _get_short (cp);
       cp += sizeof (u_short);
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__FreeBSD__)
       GETSHORT(weight, cp);
 #else
       NS_GET16 (weight, cp);
 #endif
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) ||\
-    defined(OLD_NAMESER) || defined(__FreeBSD__)
+    defined(OLD_NAMESER)
       port = _get_short (cp);
       cp += sizeof (u_short);
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__FreeBSD__)
       GETSHORT(port, cp);
 #else
       NS_GET16 (port, cp);
