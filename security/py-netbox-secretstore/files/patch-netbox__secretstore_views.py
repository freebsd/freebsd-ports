From: Daniel Sheppard <dans@dansheps.com>
Date: Tue, 11 Apr 2023 08:34:04 -0500
Subject: [PATCH] #12087 - Fix Bulk Edit update when M2M operations are present.

Obtained from:

https://github.com/DanSheps/netbox-secretstore/commit/7ad1ba639aa077c45bcac05dc025132c6bd9139e.patch

--- netbox_secretstore/views.py.orig	2022-12-31 01:50:00 UTC
+++ netbox_secretstore/views.py
@@ -156,15 +156,15 @@ class SecretEditView(ObjectEditView):
                     secret.plaintext = str(form.cleaned_data['plaintext'])
                     secret.encrypt(master_key)
 
-            secret.save()
-            form.save_m2m()
+                    secret.save()
+                    form.save_m2m()
 
-            msg = '{} secret'.format('Created' if not form.instance.pk else 'Modified')
-            logger.info(f"{msg} {secret} (PK: {secret.pk})")
-            msg = f'{msg} <a href="{secret.get_absolute_url()}">{escape(secret)}</a>'
-            messages.success(request, mark_safe(msg))
+                    msg = '{} secret'.format('Created' if not form.instance.pk else 'Modified')
+                    logger.info(f"{msg} {secret} (PK: {secret.pk})")
+                    msg = f'{msg} <a href="{secret.get_absolute_url()}">{escape(secret)}</a>'
+                    messages.success(request, mark_safe(msg))
 
-            return redirect(self.get_return_url(request, secret))
+                    return redirect(self.get_return_url(request, secret))
 
         else:
             logger.debug("Form validation failed")
