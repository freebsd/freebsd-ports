Index: hpgl-input.c
===================================================================
RCS file: /development/cvs/cups/filter/hpgl-input.c,v
retrieving revision 1.16
diff -u -r1.16 hpgl-input.c
--- filter/hpgl-input.c	25 Feb 2004 20:14:52 -0000	1.16
+++ filter/hpgl-input.c	16 Dec 2004 19:38:12 -0000
@@ -54,7 +54,8 @@
 		ch,		/* Current char */
 		done,		/* Non-zero when the current command is read */
 		i;		/* Looping var */
-  char		buf[262144];	/* String buffer */
+  char		buf[262144],	/* String buffer */
+		*bufptr;	/* Pointer into buffer */
   static param_t p[MAX_PARAMS];	/* Parameter buffer */
 
 
@@ -128,9 +129,12 @@
 
   if (strcasecmp(name, "LB") == 0)
   {
-    for (i = 0; (ch = getc(fp)) != StringTerminator; i ++)
-      buf[i] = ch;
-    buf[i] = '\0';
+    bufptr = buf;
+    while ((ch = getc(fp)) != StringTerminator)
+      if (bufptr < (buf + sizeof(buf) - 1))
+        *bufptr++ = ch;
+    *bufptr = '\0';
+
     p[num_params].type         = PARAM_STRING;
     p[num_params].value.string = strdup(buf);
     num_params ++;
@@ -155,11 +159,12 @@
   }
   else if (strcasecmp(name, "PE") == 0)
   {
-    for (i = 0; i < (sizeof(buf) - 1); i ++)
-      if ((buf[i] = getc(fp)) == ';')
-        break;
+    bufptr = buf;
+    while ((ch = getc(fp)) != ';')
+      if (bufptr < (buf + sizeof(buf) - 1))
+        *bufptr++ = ch;
+    *bufptr = '\0';
 
-    buf[i] = '\0';
     p[num_params].type         = PARAM_STRING;
     p[num_params].value.string = strdup(buf);
     num_params ++;
