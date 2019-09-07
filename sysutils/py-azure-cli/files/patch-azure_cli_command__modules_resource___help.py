# Part of
# https://github.com/Azure/azure-cli/commit/b33944353f474a35cae113b1496e90822d2eb8c6
--- azure/cli/command_modules/resource/_help.py.orig	2019-09-07 20:28:46 UTC
+++ azure/cli/command_modules/resource/_help.py
@@ -799,6 +799,19 @@ examples:
                 "effect": "deny"
             }
         }'
+  - name: Create a policy definition with mode. The mode 'Indexed' indicates the policy should be evaluated only for resource types that support tags and location.
+    text: |
+        az policy definition create --name TagsPolicyDefinition --subscription 'MySubscription' --mode Indexed --rules '{
+            "if":
+            {
+                "field": "tags",
+                "exists": "false"
+            },
+            "then":
+            {
+                "effect": "deny"
+            }
+        }'
 """
 
 helps['policy definition delete'] = """
