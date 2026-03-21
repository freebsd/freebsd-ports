Fixes following warnings/exceptions:

UserWarning: FilterLookup[str] may cause DuplicatedTypeName errors. Use StrFilterLookup instead

Obtained from:

https://github.com/Onemind-Services-LLC/netbox-secrets/pull/239

--- netbox_secrets/graphql/filters.py.orig	2026-03-18 09:11:43 UTC
+++ netbox_secrets/graphql/filters.py
@@ -3,7 +3,7 @@ from strawberry.scalars import ID
 import strawberry
 import strawberry_django
 from strawberry.scalars import ID
-from strawberry_django import FilterLookup
+from strawberry_django import StrFilterLookup
 
 from netbox.graphql.filters import (
     OrganizationalModelFilter,
@@ -36,8 +36,8 @@ class SecretRoleFilter(OrganizationalModelFilter):
 
 
 @strawberry_django.filter_type(Secret, lookups=True)
-class SecretFilter(ContactFilterMixin, PrimaryModelFilter):
-    name: FilterLookup[str] | None = strawberry_django.filter_field()
+class SecretFilter(PrimaryModelFilter, ContactFilterMixin):
+    name: StrFilterLookup[str] | None = strawberry_django.filter_field()
     role: Annotated[
         'SecretRoleFilter', strawberry.lazy('netbox_secrets.graphql.filters')
     ] | None = strawberry_django.filter_field()
