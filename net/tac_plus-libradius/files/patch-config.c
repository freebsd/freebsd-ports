--- ./config.c.orig	2001-03-16 10:04:27.000000000 +0100
+++ ./config.c	2011-08-29 00:31:55.000000000 +0200
@@ -109,7 +109,7 @@
 static int no_user_dflt = 0;	/* default if user doesn't exist */
 static char *authen_default = NULL;	/* top level authentication default */
 static int authen_default_method = 0; /*For method check */
-static char *nopasswd_str = "nopassword";
+char *nopasswd_str = "nopassword";
 
 /* A host definition structure. Currently unused, but when we start
    configuring host-specific information e.g. per-host keys, this is
@@ -603,6 +603,12 @@
 		authen_default_method = sym_code;
 		break;
 #endif
+#ifdef USE_RADIUS
+		case S_radius:
+		fprintf(stderr,"sym_code=%i, radius\n",sym_code);
+		authen_default_method = sym_code;
+                break;
+#endif
                 
  
 		default:
