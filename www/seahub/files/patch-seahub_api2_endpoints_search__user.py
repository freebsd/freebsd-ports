--- seahub/api2/endpoints/search_user.py.orig	2019-03-13 07:50:12 UTC
+++ seahub/api2/endpoints/search_user.py
@@ -1,7 +1,6 @@
 # Copyright (c) 2012-2016 Seafile Ltd.
 import os
 import sys
-import json
 import logging
 
 from django.db.models import Q
@@ -125,12 +124,13 @@ class SearchUser(APIView):
         email_result = []
 
         # remove nonexistent or inactive user
-        email_list_json = json.dumps(email_list)
-        user_obj_list = ccnet_api.get_emailusers_in_list('DB', email_list_json) + \
-                ccnet_api.get_emailusers_in_list('LDAP', email_list_json)
-        for user_obj in user_obj_list:
-            if user_obj.is_active:
-                email_result.append(user_obj.email)
+	for email in email_list:
+		try:
+			user = User.objects.get(email=email)
+			if user.is_active:
+				email_result.append(email)
+		except User.DoesNotExist:
+			continue
 
         if django_settings.ENABLE_ADDRESSBOOK_OPT_IN:
             # get users who has setted to show in address book
@@ -178,9 +178,6 @@ def format_searched_user_result(request, users, size):
     return results
 
 def search_user_from_ccnet(q):
-    """ Return 10 items at most.
-    """
-
     users = []
 
     db_users = ccnet_api.search_emailusers('DB', q, 0, 10)
@@ -204,12 +201,10 @@ def search_user_from_ccnet(q):
     return email_list
 
 def search_user_from_profile(q):
-    """ Return 10 items at most.
-    """
     # 'nickname__icontains' for search by nickname
     # 'contact_email__icontains' for search by contact email
     users = Profile.objects.filter(Q(nickname__icontains=q) | \
-            Q(contact_email__icontains=q)).values('user')[:10]
+            Q(contact_email__icontains=q)).values('user')
 
     email_list = []
     for user in users:
@@ -218,11 +213,9 @@ def search_user_from_profile(q):
     return email_list
 
 def search_user_from_profile_with_limits(q, limited_emails):
-    """ Return 10 items at most.
-    """
     # search within limited_emails
     users = Profile.objects.filter(Q(user__in=limited_emails) &
-            (Q(nickname__icontains=q) | Q(contact_email__icontains=q))).values('user')[:10]
+            (Q(nickname__icontains=q) | Q(contact_email__icontains=q))).values('user')
 
     email_list = []
     for user in users:
@@ -231,8 +224,6 @@ def search_user_from_profile_with_limits(q, limited_em
     return email_list
 
 def search_user_when_global_address_book_disabled(request, q):
-    """ Return 10 items at most.
-    """
 
     email_list = []
     username = request.user.username
