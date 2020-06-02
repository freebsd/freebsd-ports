--- src/auths/call_radius.c.orig	2020-05-30 22:35:38.000000000 +0200
+++ src/auths/call_radius.c	2020-06-01 19:54:14.402105000 +0200
@@ -113,37 +113,37 @@
 
 #ifdef RADIUS_LIB_RADIUSCLIENT
 if (rc_read_config(RADIUS_CONFIG_FILE) != 0)
-  *errptr = string_sprintf("RADIUS: can't open %s", RADIUS_CONFIG_FILE);
+  *errptr = string_sprintf("%s", "RADIUS: can't open %s", RADIUS_CONFIG_FILE);
 
 else if (rc_read_dictionary(rc_conf_str("dictionary")) != 0)
-  *errptr = US"RADIUS: can't read dictionary";
+  *errptr = string_sprintf("%s", "RADIUS: can't read dictionary");
 
 else if (!rc_avpair_add(&send, PW_USER_NAME, user, 0))
-  *errptr = US"RADIUS: add user name failed";
+  *errptr = string_sprintf("%s", "RADIUS: add user name failed\n");
 
 else if (!rc_avpair_add(&send, PW_USER_PASSWORD, CS radius_args, 0))
-  *errptr = US"RADIUS: add password failed");
+  *errptr = string_sprintf("%s", "RADIUS: add password failed\n");
 
 else if (!rc_avpair_add(&send, PW_SERVICE_TYPE, &service, 0))
-  *errptr = US"RADIUS: add service type failed";
+  *errptr = string_sprintf("%s", "RADIUS: add service type failed\n");
 
 #else  /* RADIUS_LIB_RADIUSCLIENT unset => RADIUS_LIB_RADIUSCLIENT2 */
 
 if (!(h = rc_read_config(RADIUS_CONFIG_FILE)))
-  *errptr = string_sprintf("RADIUS: can't open %s", RADIUS_CONFIG_FILE);
+  *errptr = string_sprintf("%s", "RADIUS: can't open %s", RADIUS_CONFIG_FILE);
 
 else if (rc_read_dictionary(h, rc_conf_str(h, "dictionary")) != 0)
-  *errptr = US"RADIUS: can't read dictionary";
+  *errptr = string_sprintf("%s", "RADIUS: can't read dictionary");
 
 else if (!rc_avpair_add(h, &send, PW_USER_NAME, user, Ustrlen(user), 0))
-  *errptr = US"RADIUS: add user name failed";
+  *errptr = string_sprintf("%s", "RADIUS: add user name failed\n");
 
 else if (!rc_avpair_add(h, &send, PW_USER_PASSWORD, CS radius_args,
     Ustrlen(radius_args), 0))
-  *errptr = US"RADIUS: add password failed";
+  *errptr = string_sprintf("%s", "RADIUS: add password failed\n");
 
 else if (!rc_avpair_add(h, &send, PW_SERVICE_TYPE, &service, 0, 0))
-  *errptr = US"RADIUS: add service type failed";
+  *errptr = string_sprintf("%s", "RADIUS: add service type failed\n");
 
 #endif  /* RADIUS_LIB_RADIUSCLIENT */
 
@@ -176,7 +176,7 @@
 
   case BADRESP_RC:
   default:
-    *errptr = string_sprintf("RADIUS: unexpected response (%d)", result);
+    *errptr = string_sprintf("%s", "RADIUS: unexpected response (%d)", result);
     return ERROR;
   }
 
@@ -186,7 +186,7 @@
 
 if (!(h = rad_auth_open()))
   {
-  *errptr = string_sprintf("RADIUS: can't initialise libradius");
+  *errptr = string_sprintf("%s", "RADIUS: can't initialise libradius");
   return ERROR;
   }
 if (rad_config(h, RADIUS_CONFIG_FILE) != 0 ||
@@ -196,7 +196,7 @@
     rad_put_int(h, RAD_SERVICE_TYPE, RAD_AUTHENTICATE_ONLY) != 0 ||
     rad_put_string(h, RAD_NAS_IDENTIFIER, CS primary_hostname) != 0)
   {
-  *errptr = string_sprintf("RADIUS: %s", rad_strerror(h));
+  *errptr = string_sprintf("%s", "RADIUS: %s", rad_strerror(h));
   result = ERROR;
   }
 else
@@ -211,12 +211,12 @@
       break;
 
     case -1:
-      *errptr = string_sprintf("RADIUS: %s", rad_strerror(h));
+      *errptr = string_sprintf("%s", "RADIUS: %s", rad_strerror(h));
       result = ERROR;
       break;
 
     default:
-      *errptr = string_sprintf("RADIUS: unexpected response (%d)", result);
+      *errptr = string_sprintf("%s", "RADIUS: unexpected response (%d)", result);
       result= ERROR;
       break;
     }
