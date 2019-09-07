# Part of
# https://github.com/Azure/azure-cli/commit/b33944353f474a35cae113b1496e90822d2eb8c6
--- azure/cli/command_modules/resource/_params.py.orig	2019-09-07 20:29:39 UTC
+++ azure/cli/command_modules/resource/_params.py
@@ -102,7 +102,6 @@ def load_arguments(self, _):
         c.argument('resource_group_name', arg_type=resource_group_name_type, help='the resource group where the policy will be applied')
 
     with self.argument_context('policy definition', resource_type=ResourceType.MGMT_RESOURCE_POLICY) as c:
-        from azure.mgmt.resource.policy.models import PolicyMode
         c.argument('policy_definition_name', arg_type=existing_policy_definition_name_type)
         c.argument('rules', help='JSON formatted string or a path to a file with such content', type=file_type, completer=FilesCompleter())
         c.argument('display_name', help='Display name of policy definition.')
@@ -110,7 +109,7 @@ def load_arguments(self, _):
         c.argument('params', help='JSON formatted string or a path to a file or uri with parameter definitions.', type=file_type, completer=FilesCompleter(), min_api='2016-12-01')
         c.argument('metadata', min_api='2017-06-01-preview', nargs='+', validator=validate_metadata, help='Metadata in space-separated key=value pairs.')
         c.argument('management_group', arg_type=management_group_name_type)
-        c.argument('mode', arg_type=get_enum_type(PolicyMode), options_list=['--mode', '-m'], help='Mode of the policy definition.', min_api='2016-12-01')
+        c.argument('mode', options_list=['--mode', '-m'], help='Mode of the policy definition, e.g. All, Indexed. Please visit https://aka.ms/azure-policy-mode for more information.', min_api='2016-12-01')
         c.argument('subscription', arg_type=subscription_type)
         c.ignore('_subscription')  # disable global subscription
 
