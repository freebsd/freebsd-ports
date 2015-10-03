--- pootle/apps/registration/models.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/registration/models.py
@@ -1,4 +1,5 @@
 import datetime
+import hashlib
 import random
 import re
 
@@ -8,7 +9,6 @@ from django.contrib.sites.models import 
 from django.db import models
 from django.db import transaction
 from django.template.loader import render_to_string
-from django.utils.hashcompat import sha_constructor
 from django.utils.translation import ugettext_lazy as _
 
 
@@ -146,7 +146,7 @@ class RegistrationManager(models.Manager
                 msg.send()
         user_registered.send(sender=self.model, user=new_user)
         return new_user
-    create_inactive_user = transaction.commit_on_success(create_inactive_user)
+    create_inactive_user = transaction.atomic(create_inactive_user)
 
     def create_profile(self, user):
         """
@@ -158,8 +158,8 @@ class RegistrationManager(models.Manager
         username and a random salt.
 
         """
-        salt = sha_constructor(str(random.random())).hexdigest()[:5]
-        activation_key = sha_constructor(salt+user.email).hexdigest()
+        salt = hashlib.sha1(str(random.random())).hexdigest()[:5]
+        activation_key = hashlib.sha1(salt+user.email).hexdigest()
         return self.create(user=user,
                            activation_key=activation_key)
 
