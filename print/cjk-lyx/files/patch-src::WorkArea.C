--- src/WorkArea.C.orig	Fri Aug 23 15:04:29 2002
+++ src/WorkArea.C	Thu Oct  3 00:30:28 2002
@@ -409,9 +409,9 @@
 		KeySym keysym = 0;
 #ifdef I18N
                char s_r[256];
-#else
-		char dummy[1];
+               int num_bytes;
 #endif		
+		char dummy[1];
 		XKeyEvent * xke = reinterpret_cast<XKeyEvent *>(ev);
 #if FL_VERSION < 1 && (FL_REVISION < 89 || (FL_REVISION == 89 && FL_FIXLEVEL < 5))
 		// XForms < 0.89.5 does not have compose support
