--- src/lib.c.orig	Thu May 25 12:28:53 2006
+++ src/lib.c	Thu May 25 12:30:17 2006
@@ -306,6 +306,9 @@
 			rc = gethostbyname_r(val, &he_b, &he_d);
 			if ( !rc ) he = &he_b;
 			    else   he = NULL;
+#elif  defined(__FreeBSD__)
+			gethostbyname_r(val, &he_b, he_strb, sizeof(he_strb), &he, &he_errno);
+
 #else
 			he = gethostbyname_r(val, &he_b, he_strb, sizeof(he_strb), &he_errno);
 #endif
