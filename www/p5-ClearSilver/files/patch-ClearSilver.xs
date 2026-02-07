--- ClearSilver.xs.orig	2008-10-04 15:16:18.000000000 +0000
+++ ClearSilver.xs	2008-10-04 15:20:37.000000000 +0000
@@ -401,7 +401,11 @@
 	ClearSilver::CS cs
     CODE:
     {
-	SV *str = newSV(0);
+	SV *str = newSV(1);
+	SvLEN_set(str, 0);
+	SvCUR_set(str, 0);
+	SvPOK_on(str);
+
 	cs->err = cs_render(cs->cs, str, output);
 	if (cs->err == STATUS_OK) {
 	  ST(0) = sv_2mortal(str);
@@ -439,7 +443,7 @@
     CODE:
 	do {
 	    len = strlen(in_str);
-	    cs_str = (char *)malloc(len);
+	    cs_str = (char *)malloc(len + 1);
 	    if (!cs_str) {
 	        RETVAL = 0;
 		break;
@@ -448,7 +452,8 @@
             cs->err =  cs_parse_string(cs->cs, cs_str, len);
 	    if (cs->err != STATUS_OK)
 		RETVAL = 0;
-	    RETVAL = 1;
+	    else
+	        RETVAL = 1;
        } while (0);
     OUTPUT:
         RETVAL
