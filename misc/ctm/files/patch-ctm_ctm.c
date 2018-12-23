--- ctm/ctm.c.orig	2018-10-27 15:56:22 UTC
+++ ctm/ctm.c
@@ -213,6 +213,22 @@ Proc(char *filename, unsigned applied)
 	strcat(p,filename);
 	f = popen(p,"r");
 	if(!f) { warn("%s", p); return Exit_Garbage; }
+    } else if(p && !strcmp(p,".bz2")) {
+	p = alloca(20 + strlen(filename));
+	strcpy(p,"bzcat < ");
+	strcat(p,filename);
+	f = popen(p,"r");
+	if(!f) { warn("%s", p); return Exit_Garbage; }
+    } else if(p && !strcmp(p,".xz")) {
+	if (system("which -s xz") != 0) {
+	    fprintf(stderr, "xz is not found in $PATH.  You can install it from ports, or adjust $PATH.\n");
+	    return Exit_Garbage;
+	}
+	p = alloca(20 + strlen(filename));
+	strcpy(p,"xz -dc < ");
+	strcat(p,filename);
+	f = popen(p,"r");
+	if(!f) { warn("%s", p); return Exit_Garbage; }
     } else {
 	p = 0;
 	f = fopen(filename,"r");
