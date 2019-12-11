Fix exception on password change page for local users

Obtained from:
https://github.com/netbox-community/netbox/commit/3b03d68ac70be1b5b9912d0a4d2a5fecd25cede4

--- netbox/users/views.py.orig	2019-12-10 15:47:48 UTC
+++ netbox/users/views.py
@@ -96,7 +96,7 @@ class ChangePasswordView(LoginRequiredMixin, View):
 
     def get(self, request):
         # LDAP users cannot change their password here
-        if getattr(request.user, 'ldap_username'):
+        if getattr(request.user, 'ldap_username', None):
             messages.warning(request, "LDAP-authenticated user credentials cannot be changed within NetBox.")
             return redirect('user:profile')
 
