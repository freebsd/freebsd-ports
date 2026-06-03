--- examples/pamtest.py.orig	2026-05-24 16:03:37 UTC
+++ examples/pamtest.py
@@ -6,42 +6,42 @@ def pam_conv(auth, query_list, userData):
 
 def pam_conv(auth, query_list, userData):
 
-	resp = []
+    resp = []
 
-	for i in range(len(query_list)):
-		query, type = query_list[i]
-		if type == PAM.PAM_PROMPT_ECHO_ON:
-			val = raw_input(query)
-			resp.append((val, 0))
-		elif type == PAM.PAM_PROMPT_ECHO_OFF:
-			val = getpass(query)
-			resp.append((val, 0))
-		elif type == PAM.PAM_PROMPT_ERROR_MSG or type == PAM.PAM_PROMPT_TEXT_INFO:
-			print query
-			resp.append(('', 0))
-		else:
-			return None
+    for i in range(len(query_list)):
+        query, type = query_list[i]
+        if type == PAM.PAM_PROMPT_ECHO_ON:
+            val = raw_input(query)
+            resp.append((val, 0))
+        elif type == PAM.PAM_PROMPT_ECHO_OFF:
+            val = getpass(query)
+            resp.append((val, 0))
+        elif type == PAM.PAM_ERROR_MSG or type == PAM.PAM_TEXT_INFO:
+            print(query)
+            resp.append(('', 0))
+        else:
+            return None
 
-	return resp
+    return resp
 
 service = 'passwd'
 
 if len(sys.argv) == 2:
-	user = sys.argv[1]
+    user = sys.argv[1]
 else:
-	user = None
+    user = None
 
 auth = PAM.pam()
 auth.start(service)
 if user != None:
-	auth.set_item(PAM.PAM_USER, user)
+    auth.set_item(PAM.PAM_USER, user)
 auth.set_item(PAM.PAM_CONV, pam_conv)
 try:
-	auth.authenticate()
-	auth.acct_mgmt()
-except PAM.error, resp:
-	print 'Go away! (%s)' % resp
+    auth.authenticate()
+    auth.acct_mgmt()
+except PAM.error as resp:
+    print('Go away! (%s)' % resp)
 except:
-	print 'Internal error'
+    print('Internal error')
 else:
-	print 'Good to go!'
+    print('Good to go!')
