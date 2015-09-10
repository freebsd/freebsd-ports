--- rsb_init.c.orig	2015-05-01 21:04:42 UTC
+++ rsb_init.c
@@ -50,13 +50,15 @@ const rsb_char_t * rsb__init_get_mem_hie
 	if((usmhi = getenv("RSB_USER_SET_MEM_HIERARCHY_INFO"))!=NULL && *usmhi)
 		goto done;
 #endif /* RSB_HAVE_GETENV */
+#ifdef RSB_DETECTED_MEM_HIERARCHY_INFO
+	if(verbose) RSB_INFO("Checking hardcoded RSB_DETECTED_MEM_HIERARCHY_INFO symbol\n");
+	usmhi = RSB_DETECTED_MEM_HIERARCHY_INFO;
+	if (*usmhi)
+		goto done;
 #ifdef RSB_USER_SET_MEM_HIERARCHY_INFO
 	if(verbose) RSB_INFO("Checking hardcoded RSB_USER_SET_MEM_HIERARCHY_INFO symbol\n");
 	usmhi = RSB_USER_SET_MEM_HIERARCHY_INFO;
 #endif /* RSB_USER_SET_MEM_HIERARCHY_INFO */
-#ifdef RSB_DETECTED_MEM_HIERARCHY_INFO
-	if(verbose) RSB_INFO("Checking hardcoded RSB_DETECTED_MEM_HIERARCHY_INFO symbol\n");
-	usmhi = RSB_DETECTED_MEM_HIERARCHY_INFO;
 #endif /* RSB_USER_SET_MEM_HIERARCHY_INFO */
 done:
 	if(verbose) RSB_INFO("Available memory hierarchy info string: \"%s\"\n",usmhi);
