--- iiimxcf/xiiimp.so/iiimp/iiimpIM.c	Wed Aug 25 15:09:50 2004
+++ iiimxcf/xiiimp.so/iiimp/iiimpIM.c	Wed Feb 16 22:06:57 2005
@@ -189,7 +189,7 @@
 };
 
 #ifndef IMLOCALEDIR
-#define IMLOCALEDIR "/usr/lib/im/locale"
+#define IMLOCALEDIR (IMDIR "/locale")
 #endif
 
 #define	iscomment(ch)	((ch) == '\0' || (ch) == '#')
@@ -625,7 +625,7 @@
 	if (mod) {
 	    mod += strlen(MODIFIER);
 
-	    if (!strncmp(mod, "iiimp/", 6) || !strncmp(mod, "IIIMP/", 6)) {
+	    if (!strncasecmp(mod, "iiimp/", 6)) {
 		mod += 6;
 
 		if (index(mod, ':')) {
