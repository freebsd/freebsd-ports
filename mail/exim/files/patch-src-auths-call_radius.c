--- src/auths/call_radius.c.orig	2019-12-08 12:53:48 UTC
+++ src/auths/call_radius.c
@@ -112,37 +112,37 @@ rc_openlog("exim");
 
 #ifdef RADIUS_LIB_RADIUSCLIENT
 if (rc_read_config(RADIUS_CONFIG_FILE) != 0)
-  *errptr = string_sprintf("RADIUS: can't open %s", RADIUS_CONFIG_FILE);
+  *errptr = string_sprintf("%s", "RADIUS: can't open %s", RADIUS_CONFIG_FILE);
 
 else if (rc_read_dictionary(rc_conf_str("dictionary")) != 0)
-  *errptr = string_sprintf("RADIUS: can't read dictionary");
+  *errptr = string_sprintf("%s", "RADIUS: can't read dictionary");
 
 else if (rc_avpair_add(&send, PW_USER_NAME, user, 0) == NULL)
-  *errptr = string_sprintf("RADIUS: add user name failed\n");
+  *errptr = string_sprintf("%s", "RADIUS: add user name failed\n");
 
 else if (rc_avpair_add(&send, PW_USER_PASSWORD, CS radius_args, 0) == NULL)
-  *errptr = string_sprintf("RADIUS: add password failed\n");
+  *errptr = string_sprintf("%s", "RADIUS: add password failed\n");
 
 else if (rc_avpair_add(&send, PW_SERVICE_TYPE, &service, 0) == NULL)
-  *errptr = string_sprintf("RADIUS: add service type failed\n");
+  *errptr = string_sprintf("%s", "RADIUS: add service type failed\n");
 
 #else  /* RADIUS_LIB_RADIUSCLIENT unset => RADIUS_LIB_RADIUSCLIENT2 */
 
 if ((h = rc_read_config(RADIUS_CONFIG_FILE)) == NULL)
-  *errptr = string_sprintf("RADIUS: can't open %s", RADIUS_CONFIG_FILE);
+  *errptr = string_sprintf("%s", "RADIUS: can't open %s", RADIUS_CONFIG_FILE);
 
 else if (rc_read_dictionary(h, rc_conf_str(h, "dictionary")) != 0)
-  *errptr = string_sprintf("RADIUS: can't read dictionary");
+  *errptr = string_sprintf("%s", "RADIUS: can't read dictionary");
 
 else if (rc_avpair_add(h, &send, PW_USER_NAME, user, Ustrlen(user), 0) == NULL)
-  *errptr = string_sprintf("RADIUS: add user name failed\n");
+  *errptr = string_sprintf("%s", "RADIUS: add user name failed\n");
 
 else if (rc_avpair_add(h, &send, PW_USER_PASSWORD, CS radius_args,
     Ustrlen(radius_args), 0) == NULL)
-  *errptr = string_sprintf("RADIUS: add password failed\n");
+  *errptr = string_sprintf("%s", "RADIUS: add password failed\n");
 
 else if (rc_avpair_add(h, &send, PW_SERVICE_TYPE, &service, 0, 0) == NULL)
-  *errptr = string_sprintf("RADIUS: add service type failed\n");
+  *errptr = string_sprintf("%s", "RADIUS: add service type failed\n");
 
 #endif  /* RADIUS_LIB_RADIUSCLIENT */
 
@@ -175,7 +175,7 @@ switch (result)
 
   default:
   case BADRESP_RC:
-  *errptr = string_sprintf("RADIUS: unexpected response (%d)", result);
+  *errptr = string_sprintf("%s", "RADIUS: unexpected response (%d)", result);
   return ERROR;
   }
 
@@ -186,7 +186,7 @@ switch (result)
 h = rad_auth_open();
 if (h == NULL)
   {
-  *errptr = string_sprintf("RADIUS: can't initialise libradius");
+  *errptr = string_sprintf("%s", "RADIUS: can't initialise libradius");
   return ERROR;
   }
 if (rad_config(h, RADIUS_CONFIG_FILE) != 0 ||
@@ -196,7 +196,7 @@ if (rad_config(h, RADIUS_CONFIG_FILE) != 0 ||
     rad_put_int(h, RAD_SERVICE_TYPE, RAD_AUTHENTICATE_ONLY) != 0 ||
     rad_put_string(h, RAD_NAS_IDENTIFIER, CS primary_hostname) != 0)
   {
-  *errptr = string_sprintf("RADIUS: %s", rad_strerror(h));
+  *errptr = string_sprintf("%s", "RADIUS: %s", rad_strerror(h));
   result = ERROR;
   }
 else
@@ -214,12 +214,12 @@ else
     break;
 
     case -1:
-    *errptr = string_sprintf("RADIUS: %s", rad_strerror(h));
+    *errptr = string_sprintf("%s", "RADIUS: %s", rad_strerror(h));
     result = ERROR;
     break;
 
     default:
-    *errptr = string_sprintf("RADIUS: unexpected response (%d)", result);
+    *errptr = string_sprintf("%s", "RADIUS: unexpected response (%d)", result);
     result= ERROR;
     break;
     }
