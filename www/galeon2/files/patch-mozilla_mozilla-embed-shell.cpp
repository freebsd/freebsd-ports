--- mozilla/mozilla-embed-shell.cpp.orig	Mon Apr  7 18:39:50 2003
+++ mozilla/mozilla-embed-shell.cpp	Mon Apr  7 18:39:59 2003
@@ -42,6 +42,7 @@
 #include <nsICacheService.h>
 #include <nsCOMPtr.h>
 #include <nsNetCID.h>
+#include <nsNetUtil.h>
 #include <nsIServiceManager.h>
 #include <nsIIOService.h>
 #include <nsIProtocolProxyService.h>
@@ -848,17 +849,26 @@
 }
 
 static gresult           
-impl_set_permission (GaleonEmbedShell *shell,
-		     const char *url, 
-		     PermissionType type,
-		     gboolean allow)
+impl_set_permission(GaleonEmbedShell *shell,
+		    const char *url, 
+		    PermissionType type,
+		    gboolean allow)
 {
 	nsresult rv;
 	nsCOMPtr<nsIPermissionManager> permissionManager =
-                        do_CreateInstance (NS_PERMISSIONMANAGER_CONTRACTID);
+                        do_GetService(NS_PERMISSIONMANAGER_CONTRACTID);
 
-        rv = permissionManager->Add (nsDependentCString(url),
-        			     allow ? PR_TRUE : PR_FALSE, type);
+#if MOZILLA_SNAPSHOT > 6
+	nsCOMPtr<nsIURI> uri;
+	rv = NS_NewURI(getter_AddRefs(uri), url);
+	if (NS_FAILED(rv) || !uri) return G_FAILED;
+	rv = permissionManager->Add(uri, type,
+				    allow ? (PRUint32)nsIPermissionManager::ALLOW_ACTION
+				    	  : (PRUint32)nsIPermissionManager::DENY_ACTION);
+#else
+        rv = permissionManager->Add(nsDependentCString(url),
+        			    allow ? PR_TRUE : PR_FALSE, type);
+#endif
 	if (NS_FAILED(rv)) return G_FAILED;
 
 	return G_OK;
@@ -874,9 +884,9 @@
 	*permissions = NULL;
 	
 	nsCOMPtr<nsIPermissionManager> permissionManager = 
-                        do_CreateInstance (NS_PERMISSIONMANAGER_CONTRACTID);
+                        do_GetService(NS_PERMISSIONMANAGER_CONTRACTID);
         nsCOMPtr<nsISimpleEnumerator> permissionEnumerator;
-        result = permissionManager->GetEnumerator (getter_AddRefs(permissionEnumerator));
+        result = permissionManager->GetEnumerator(getter_AddRefs(permissionEnumerator));
         if (NS_FAILED(result)) return G_FAILED;
 	
         PRBool enumResult;
@@ -885,47 +895,68 @@
              permissionEnumerator->HasMoreElements(&enumResult))
         {
                 nsCOMPtr<nsIPermission> nsPermission;
-                result = permissionEnumerator->GetNext (getter_AddRefs(nsPermission));
+                result = permissionEnumerator->GetNext(getter_AddRefs(nsPermission));
                 if (NS_FAILED(result)) return G_FAILED;
 
+#if MOZILLA_SNAPSHOT > 6
+		PRUint32 cType;
+#else
                 PRInt32 cType;
-                nsPermission->GetType (&cType);
-                if (cType == type)
+#endif
+                nsPermission->GetType(&cType);
+                if ((PRUint32)cType == (PRUint32)type)
                 {
-                        PermissionInfo *b = g_new0 (PermissionInfo, 1);
-                        gchar *tmp = NULL;
-
-                        nsPermission->GetHost (&tmp);
-                        b->domain = g_strdup (tmp);
-                        nsMemory::Free (tmp);
+                        PermissionInfo *b = g_new0(PermissionInfo, 1);
+#if MOZILLA_SNAPSHOT > 6
+			nsCString host;
+			nsPermission->GetHost(host);
+			b->domain = g_strdup(host.get());
+
+			PRUint32 cap;
+			nsPermission->GetCapability(&cap);
+			switch (cap)
+			{
+			  case nsIPermissionManager::ALLOW_ACTION :
+			  	b->status = TRUE;
+			  	break;
+			  case nsIPermissionManager::DENY_ACTION :
+			 	b->status = FALSE;
+			 	break;
+			  default :
+			  	b->status = FALSE;
+			}
+#else
+			nsXPIDLCString host;
+                        nsPermission->GetHost(getter_Copies(host));
+                        b->domain = g_strdup(host.get());
 
                         PRBool cap;
-                        nsPermission->GetCapability (&cap);
+                        nsPermission->GetCapability(&cap);
 			b->status = cap;
-
-                        *permissions = g_list_prepend (*permissions, b);
+#endif
+                        *permissions = g_list_prepend(*permissions, b);
                 }
         }
 
-        *permissions = g_list_reverse (*permissions);
+        *permissions = g_list_reverse(*permissions);
 	
 	return G_OK;
 }
 
 static gresult           
-impl_remove_permissions (GaleonEmbedShell *shell,
-		         PermissionType type,
-		         GList *permissions)
+impl_remove_permissions(GaleonEmbedShell *shell,
+		        PermissionType type,
+		        GList *permissions)
 {
 	nsresult result;
         nsCOMPtr<nsIPermissionManager> permissionManager =
-                        do_CreateInstance (NS_PERMISSIONMANAGER_CONTRACTID);
+                        do_GetService(NS_PERMISSIONMANAGER_CONTRACTID);
 
         for (GList *l = permissions; l != NULL; l = l->next)
         {
                 PermissionInfo *b = (PermissionInfo *)l->data;
-                result = permissionManager->Remove (nsDependentCString(b->domain),
-                				    type);
+                result = permissionManager->Remove(nsDependentCString(b->domain),
+                				   type);
                 if (NS_FAILED(result)) return G_FAILED;
         };
 
@@ -937,28 +968,27 @@
 		   GList **cookies)
 {
         nsresult result;
-
         nsCOMPtr<nsICookieManager> cookieManager = 
-                        do_CreateInstance (NS_COOKIEMANAGER_CONTRACTID);
+                        do_GetService(NS_COOKIEMANAGER_CONTRACTID);
         nsCOMPtr<nsISimpleEnumerator> cookieEnumerator;
         result = 
-            cookieManager->GetEnumerator (getter_AddRefs(cookieEnumerator));
+            cookieManager->GetEnumerator(getter_AddRefs(cookieEnumerator));
         if (NS_FAILED(result)) return G_FAILED;
-	
+
         PRBool enumResult;
         for (cookieEnumerator->HasMoreElements(&enumResult) ;
              enumResult == PR_TRUE ;
              cookieEnumerator->HasMoreElements(&enumResult))
         {
                 nsCOMPtr<nsICookie> nsCookie;
-                result = cookieEnumerator->GetNext (getter_AddRefs(nsCookie));
+                result = cookieEnumerator->GetNext(getter_AddRefs(nsCookie));
                 if (NS_FAILED(result)) return G_FAILED;
 
-                CookieInfo *c = mozilla_cookie_to_info (nsCookie);
-                *cookies = g_list_prepend (*cookies, c);
+                CookieInfo *c = mozilla_cookie_to_info(nsCookie);
+                *cookies = g_list_prepend(*cookies, c);
         }       
 
-	*cookies = g_list_reverse (*cookies);
+	*cookies = g_list_reverse(*cookies);
 		
 	return G_OK;
 }
@@ -969,15 +999,15 @@
 {
 	nsresult result;
         nsCOMPtr<nsICookieManager> cookieManager =
-                        do_CreateInstance (NS_COOKIEMANAGER_CONTRACTID);
+                        do_GetService(NS_COOKIEMANAGER_CONTRACTID);
 	
         for (GList *l = cookies; l != NULL; l = l->next)
         {
                 CookieInfo *c = (CookieInfo *)l->data;
 
-                result = cookieManager->Remove (NS_LITERAL_CSTRING(c->domain),
-                                                NS_LITERAL_CSTRING(c->name),
-                                                NS_LITERAL_CSTRING(c->path),
+                result = cookieManager->Remove (nsDependentCString(c->domain),
+                                                nsDependentCString(c->name),
+                                                nsDependentCString(c->path),
                                                 PR_FALSE);
                 if (NS_FAILED(result)) return G_FAILED;
         };
@@ -993,7 +1023,7 @@
         nsresult result = NS_ERROR_FAILURE;
 
         nsCOMPtr<nsIPasswordManager> passwordManager =
-                        do_CreateInstance (NS_PASSWORDMANAGER_CONTRACTID);
+                        do_GetService(NS_PASSWORDMANAGER_CONTRACTID);
         nsCOMPtr<nsISimpleEnumerator> passwordEnumerator;
         if (type == PASSWORD_PASSWORD)
                 result = passwordManager->GetEnumerator 
@@ -1041,14 +1071,14 @@
 {
 	nsresult result = NS_ERROR_FAILURE;
         nsCOMPtr<nsIPasswordManager> passwordManager =
-                        do_CreateInstance (NS_PASSWORDMANAGER_CONTRACTID);
+                        do_GetService(NS_PASSWORDMANAGER_CONTRACTID);
 
         for (GList *l = passwords; l != NULL; l = l->next)
         {
                 PasswordInfo *p = (PasswordInfo *)l->data;
                 if (type == PASSWORD_PASSWORD)
                 {
-                        result = passwordManager->RemoveUser (NS_LITERAL_CSTRING(p->host),
+                        result = passwordManager->RemoveUser (nsDependentCString(p->host),
                                                               NS_ConvertUTF8toUCS2(nsDependentCString(p->username)));
                 }
                 else if (type == PASSWORD_REJECT)
@@ -1129,8 +1159,6 @@
         }
         else
         {
-                if (*ret_fullpath)
-                        g_free (*ret_fullpath);
                 nsCOMPtr<nsILocalFile> file;
                 filePicker->GetFile (getter_AddRefs(file));
 		nsCAutoString tempFullPathStr;
