--- fpstatic.c.orig	Tue Feb  5 16:16:46 2002
+++ fpstatic.c	Sun Apr 28 13:33:01 2002
@@ -435,6 +435,24 @@
 			snprintf((char *)fnbuf, sizeof(fnbuf), "%s%s%s%s%s",
 			    FPBASE, _EXES, _VTI_ADM, _IMAGES, pos);
 		/*
+		 * Check to see if the user is changing the password,
+		 * which has a URL like _vti_bin/_vti_aut/ passwd.htm.
+		 * It's different from other ".htm" files because it
+		 * goes through _VTI_AUT instead of _VTI_ADM and it
+		 * may not have the Lcid in the URL. If it's missing
+		 * the Lcid, hard-code it to 1033 like the rtr patches.
+		 */
+		} else if (((pos = strstr(uri, _FPPASSWD)) != NULL)) {
+			pos = strstr(uri, _VTI_AUT);
+			pos = pos + 19;
+			Lcid = (int)strtol(pos, &pos, 10);
+			if (Lcid == 0) {
+				Lcid = 1033;
+			}
+			pos = strrchr((char *)uri, '/');
+			snprintf((char *)fnbuf, sizeof(fnbuf), "%s%s%c%04d%s",
+     			    FPBASE, _ADMIN, '/', Lcid, pos);
+		/*
 		 * If we still have .htm or .css, we end up
 		 * with the admin dir. If we match, we calculate
 		 * the Lcid from the string.
