--- src/mozilla/mozilla.cpp.orig	Sat Feb 15 14:19:59 2003
+++ src/mozilla/mozilla.cpp	Thu Apr 10 13:01:20 2003
@@ -1041,17 +1041,17 @@
  * mozilla_list_cookies: get a list of all saved cookies
  */
 extern "C" GList *
-mozilla_list_cookies (void)
+mozilla_list_cookies(void)
 {
 	GList *cookies = NULL;
 	nsresult result;
 
 	nsCOMPtr<nsICookieManager> cookieManager = 
-			do_CreateInstance (NS_COOKIEMANAGER_CONTRACTID);
+			do_GetService(NS_COOKIEMANAGER_CONTRACTID);
 	nsCOMPtr<nsISimpleEnumerator> cookieEnumerator;
 	result = 
-	    cookieManager->GetEnumerator (getter_AddRefs(cookieEnumerator));
-	g_return_val_if_fail (NS_SUCCEEDED(result), NULL);	
+	    cookieManager->GetEnumerator(getter_AddRefs(cookieEnumerator));
+	g_return_val_if_fail(NS_SUCCEEDED(result), NULL);	
 	PRBool enumResult;
 	for (cookieEnumerator->HasMoreElements(&enumResult) ;
 	     enumResult == PR_TRUE ;
@@ -1060,39 +1060,39 @@
 		Cookie *c;
 	
 		nsCOMPtr<nsICookie> nsCookie;
-		result = cookieEnumerator->GetNext (getter_AddRefs(nsCookie));
-		g_return_val_if_fail (NS_SUCCEEDED(result), NULL);
+		result = cookieEnumerator->GetNext(getter_AddRefs(nsCookie));
+		g_return_val_if_fail(NS_SUCCEEDED(result), NULL);
 
-		c = g_new0 (Cookie, 1);
+		c = g_new0(Cookie, 1);
 
 		nsCAutoString transfer;
 
-		nsCookie->GetHost (transfer);
-		c->base.domain = g_strdup (transfer.get());
-		nsCookie->GetName (transfer);
-		c->name = g_strdup (transfer.get());
-		nsCookie->GetValue (transfer);
-		c->value = g_strdup (transfer.get());
-		nsCookie->GetPath (transfer);
-		c->path = g_strdup (transfer.get());
+		nsCookie->GetHost(transfer);
+		c->base.domain = g_strdup(transfer.get());
+		nsCookie->GetName(transfer);
+		c->name = g_strdup(transfer.get());
+		nsCookie->GetValue(transfer);
+		c->value = g_strdup(transfer.get());
+		nsCookie->GetPath(transfer);
+		c->path = g_strdup(transfer.get());
 
 		PRBool isSecure;
-		nsCookie->GetIsSecure (&isSecure);
+		nsCookie->GetIsSecure(&isSecure);
 		if (isSecure == PR_TRUE) 
-			c->secure = g_strdup (_("Yes"));
+			c->secure = g_strdup(_("Yes"));
 		else 
-			c->secure = g_strdup (_("No"));
+			c->secure = g_strdup(_("No"));
 
 		PRUint64 dateTime;
-		nsCookie->GetExpires (&dateTime);
+		nsCookie->GetExpires(&dateTime);
 		if(dateTime == 0)
-			c->expire = g_strdup (_("End of current session"));
+			c->expire = g_strdup(_("End of current session"));
 		else 
-			c->expire = g_strdup_printf ("%s",ctime((time_t*)&dateTime));
+			c->expire = g_strdup_printf("%s",ctime((time_t*)&dateTime));
 		
-		cookies = g_list_prepend (cookies, c);
+		cookies = g_list_prepend(cookies, c);
 	}	
-	cookies = g_list_reverse (cookies);
+	cookies = g_list_reverse(cookies);
 	return cookies;
 }
 
@@ -1102,16 +1102,20 @@
  */
 
 extern "C" GList *
+#if MOZILLA_SNAPSHOT > 6
+mozilla_get_permissions (guint type)
+#else
 mozilla_get_permissions (int type)
+#endif
 {
 	GList *permissions = NULL;
 	nsresult result;
 	nsCOMPtr<nsIPermissionManager> permissionManager = 
-			do_CreateInstance (NS_PERMISSIONMANAGER_CONTRACTID);
+			do_GetService(NS_PERMISSIONMANAGER_CONTRACTID);
 	nsCOMPtr<nsISimpleEnumerator> permissionEnumerator;
 	result = permissionManager->
-			GetEnumerator (getter_AddRefs(permissionEnumerator));
-	g_return_val_if_fail (NS_SUCCEEDED(result), NULL);
+			GetEnumerator(getter_AddRefs(permissionEnumerator));
+	g_return_val_if_fail(NS_SUCCEEDED(result), NULL);
 	PRBool enumResult;
 	for (permissionEnumerator->HasMoreElements(&enumResult) ;
 	     enumResult == PR_TRUE ;
@@ -1119,32 +1123,50 @@
 	{
 		nsCOMPtr<nsIPermission> nsPermission;
 		result = permissionEnumerator->
-				GetNext (getter_AddRefs(nsPermission));
-		g_return_val_if_fail (NS_SUCCEEDED(result), NULL);		
+				GetNext(getter_AddRefs(nsPermission));
+		g_return_val_if_fail(NS_SUCCEEDED(result), NULL);		
 
+#if MOZILLA_SNAPSHOT > 6
+		PRUint32 cType;
+#else
 		PRInt32 cType;
-		nsPermission->GetType (&cType);
+#endif
+		nsPermission->GetType(&cType);
 		if (cType == type)
 		{
-			BlockedHost *b = g_new0 (BlockedHost, 1);
-			gchar *tmp = NULL;
+			BlockedHost *b = g_new0(BlockedHost, 1);
 
-			nsPermission->GetHost (&tmp);
-			b->domain = g_strdup (tmp);
-			nsMemory::Free (tmp);
+#if MOZILLA_SNAPSHOT > 6
+			nsCString host;
+			nsPermission->GetHost(host);
+			b->domain = g_strdup(host.get());
+
+			PRUint32 cap;
+			nsPermission->GetCapability(&cap);
+			if (cap == nsIPermissionManager::ALLOW_ACTION) 
+				b->type = g_strdup(_("Allowed"));
+			else if (cap == nsIPermissionManager::DENY_ACTION)
+				b->type = g_strdup(_("Blocked"));
+			else
+				b->type = g_strdup(_("Unknown"));
+#else
+			nsXPIDLCString host;
+			nsPermission->GetHost(getter_Copies(host));
+			b->domain = g_strdup(host.get());
 
 			PRBool cap;
-			nsPermission->GetCapability (&cap);
-			if (cap == PR_TRUE) 
-				b->type = g_strdup (_("Allowed"));
-			else 
-				b->type = g_strdup (_("Blocked"));
+			nsPermission->GetCapability(&cap);
+			if (cap == PR_TRUE)
+				b->type = g_strdup(_("Allowed"));
+			else
+				b->type = g_strdup(_("Blocked"));
+#endif
 
-			permissions = g_list_prepend (permissions, b);
+			permissions = g_list_prepend(permissions, b);
 		}
 	}
 
-	permissions = g_list_reverse (permissions);
+	permissions = g_list_reverse(permissions);
 	return permissions;
 };
 
@@ -1152,16 +1174,25 @@
  * mozilla_set_url_permission: change permissions for a URL
  */
 extern "C" void
-mozilla_set_url_permission (const char *imgURL, gint type, gboolean allow)
+mozilla_set_url_permission(const char *imgURL, guint type, gboolean allow)
 {
 	nsCOMPtr<nsIPermissionManager> permissionManager =
-			do_CreateInstance (NS_PERMISSIONMANAGER_CONTRACTID);
+			do_GetService(NS_PERMISSIONMANAGER_CONTRACTID);
 
-#if MOZILLA_SNAPSHOT > 2
-	permissionManager->Add (nsDependentCString(imgURL),
-				allow ? PR_TRUE : PR_FALSE, type);
+#if MOZILLA_SNAPSHOT > 6
+	nsCOMPtr<nsIURI> url;
+	nsresult result = NS_NewURI(getter_AddRefs(url), nsDependentCString(imgURL));
+	if(NS_FAILED(result) || !url) return;
+
+	permissionManager->Add(url, type,
+			       allow ?
+			       static_cast<PRUint32>(nsIPermissionManager::ALLOW_ACTION) :
+			       static_cast<PRUint32>(nsIPermissionManager::DENY_ACTION));
+#elif MOZILLA_SNAPSHOT > 2
+	permissionManager->Add(nsDependentCString(imgURL),
+			       allow ? PR_TRUE : PR_FALSE, type);
 #else
-	permissionManager->Add (imgURL, allow ? PR_TRUE : PR_FALSE, type);
+	permissionManager->Add(imgURL, allow ? PR_TRUE : PR_FALSE, type);
 #endif
 }
 
@@ -1172,10 +1203,10 @@
  */
  
 extern "C" void
-mozilla_set_permission (GaleonEmbed *embed, gboolean permit, int type)
+mozilla_set_permission(GaleonEmbed *embed, gboolean allow, guint type)
 {
 	GALEON_WRAPPER(wrapper)
-	wrapper->SetSitePermission (permit ? PR_TRUE : PR_FALSE, type);
+	wrapper->SetSitePermission(allow ? PR_TRUE : PR_FALSE, type);
 }
 
 /**
@@ -1188,17 +1219,17 @@
 {
 	nsresult result;
 	nsCOMPtr<nsICookieManager> cookieManager =
-			do_CreateInstance (NS_COOKIEMANAGER_CONTRACTID);
+			do_GetService(NS_COOKIEMANAGER_CONTRACTID);
 
 	for (GList *cookies = g_list_first(gone) ; cookies!=NULL ; 
 	     cookies = g_list_next(cookies))
 	{
 		Cookie *c = (Cookie *)cookies->data;
 
-		result = cookieManager->Remove (NS_LITERAL_CSTRING(c->base.domain),
-						NS_LITERAL_CSTRING(c->name),
-					 	NS_LITERAL_CSTRING(c->path),
-						block ? PR_TRUE : PR_FALSE);
+		result = cookieManager->Remove(nsDependentCString(c->base.domain),
+					       nsDependentCString(c->name),
+					       nsDependentCString(c->path),
+					       block ? PR_TRUE : PR_FALSE);
 		if (NS_FAILED(result)) return FALSE;
 	};
 	return TRUE;
@@ -1210,21 +1241,21 @@
  * @type: type of permissions ( cookies or images )
  */
 extern "C" gboolean 
-mozilla_remove_permissions (GList *gone, int type)
+mozilla_remove_permissions (GList *gone, guint type)
 {
 	nsresult result;
 	nsCOMPtr<nsIPermissionManager> permissionManager =
-			do_CreateInstance (NS_PERMISSIONMANAGER_CONTRACTID);
+			do_GetService(NS_PERMISSIONMANAGER_CONTRACTID);
 
 	for (GList *permissions = g_list_first(gone) ; permissions != NULL;
 	     permissions = g_list_next(permissions))
 	{
 		BlockedHost *b = (BlockedHost *)permissions->data;
 #if MOZILLA_SNAPSHOT > 2
-		result = permissionManager->Remove (nsDependentCString(b->domain),
-						    type);
+		result = permissionManager->Remove(nsDependentCString(b->domain),
+						   type);
 #else
-		result = permissionManager->Remove (b->domain,type);
+		result = permissionManager->Remove(b->domain,type);
 #endif
 		if (NS_FAILED(result)) return FALSE;
 	};
@@ -1374,7 +1405,7 @@
 	nsresult result = NS_ERROR_FAILURE;
 
 	nsCOMPtr<nsIPasswordManager> passwordManager =
-			do_CreateInstance (NS_PASSWORDMANAGER_CONTRACTID);
+			do_GetService(NS_PASSWORDMANAGER_CONTRACTID);
 	nsCOMPtr<nsISimpleEnumerator> passwordEnumerator;
 	if (type == PASSWORD_PASSWORD)
 		result = passwordManager->GetEnumerator 
@@ -1392,24 +1423,24 @@
 		nsCOMPtr<nsIPassword> nsPassword;
 		result = passwordEnumerator->GetNext 
 					(getter_AddRefs(nsPassword));
-		g_return_val_if_fail (NS_SUCCEEDED(result), NULL);
+		g_return_val_if_fail(NS_SUCCEEDED(result), NULL);
 
-		Password *p = g_new0 (Password, 1);
+		Password *p = g_new0(Password, 1);
 
 		nsCAutoString transfer;
-		nsPassword->GetHost (transfer);
-		p->host = g_strdup (transfer.get());
+		nsPassword->GetHost(transfer);
+		p->host = g_strdup(transfer.get());
 
 		if (type == PASSWORD_PASSWORD)
 		{
 			nsAutoString unicodeName;
-			nsPassword->GetUser (unicodeName);
-			p->username = mozilla_unicode_to_locale (unicodeName.get());
+			nsPassword->GetUser(unicodeName);
+			p->username = mozilla_unicode_to_locale(unicodeName.get());
 		}
 		
-		passwords = g_list_prepend (passwords, p);
+		passwords = g_list_prepend(passwords, p);
 	}	
-	passwords = g_list_reverse (passwords);
+	passwords = g_list_reverse(passwords);
 	return passwords;
 }
 
@@ -1423,7 +1454,7 @@
 {
 	nsresult result = NS_ERROR_FAILURE;
 	nsCOMPtr<nsIPasswordManager> passwordManager =
-			do_CreateInstance (NS_PASSWORDMANAGER_CONTRACTID);
+			do_GetService(NS_PASSWORDMANAGER_CONTRACTID);
 
 	for (GList *passwords = g_list_first(gone) ; passwords!=NULL ; 
 	     passwords = g_list_next(passwords))
@@ -1435,14 +1466,14 @@
 							(p->username);
 
 			nsDependentString unicodeString(unicodeName);
-			result = passwordManager->RemoveUser (NS_LITERAL_CSTRING(p->host),
-							      unicodeString);
-			g_free (unicodeName);
+			result = passwordManager->RemoveUser(nsDependentCString(p->host),
+							     unicodeString);
+			g_free(unicodeName);
 		}
 		else if (type == PASSWORD_REJECT)
 		{
 			result = passwordManager->RemoveReject
-					(NS_LITERAL_CSTRING(p->host));
+					(nsDependentCString(p->host));
 		};
 
 		if (NS_FAILED(result)) return FALSE;
