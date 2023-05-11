From: Abhimanyu Saharan <desk.abhimanyu@gmail.com>
Date: Wed, 12 Apr 2023 21:01:43 +0530
Subject: [PATCH] fix migrations

Obtained from:

https://github.com/Onemind-Services-LLC/netbox-secretstore/commit/248330409413f1858daf13902fd1b409053fd846.patch

--- netbox_secretstore/models/secrets.py.orig	2022-12-31 01:50:00 UTC
+++ netbox_secretstore/models/secrets.py
@@ -21,6 +21,7 @@ from netbox_secretstore.utils import encrypt_master_ke
 from netbox_secretstore.hashers import SecretValidationHasher
 from netbox_secretstore.querysets import UserKeyQuerySet
 from netbox_secretstore.utils import encrypt_master_key, decrypt_master_key, generate_random_key
+from taggit.managers import TaggableManager
 
 
 __all__ = (
@@ -47,7 +48,7 @@ class UserKey(models.Model):
     user = models.OneToOneField(
         to=User,
         on_delete=models.CASCADE,
-        related_name='user_key',
+        related_name='user_key_secretstore',
         editable=False
     )
     public_key = models.TextField(
@@ -256,6 +257,11 @@ class SecretRole(OrganizationalModel):
         blank=True,
     )
 
+    tags = TaggableManager(
+        through='extras.TaggedItem',
+        related_name='netbox_secretstore_secretroles'
+    )
+
     objects = RestrictedQuerySet.as_manager()
 
     csv_headers = ['name', 'slug', 'description']
@@ -312,6 +318,11 @@ class Secret(NetBoxModel):
     hash = models.CharField(
         max_length=128,
         editable=False
+    )
+
+    tags = TaggableManager(
+        through='extras.TaggedItem',
+        related_name='netbox_secretstore_secret'
     )
 
     objects = RestrictedQuerySet.as_manager()
