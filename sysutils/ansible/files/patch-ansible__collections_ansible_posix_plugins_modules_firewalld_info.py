diff --git ansible_collections/ansible/posix/plugins/modules/firewalld_info.py ansible_collections/ansible/posix/plugins/modules/firewalld_info.py
index c34a362..0da6dd3 100644
--- ansible_collections/ansible/posix/plugins/modules/firewalld_info.py
+++ ansible_collections/ansible/posix/plugins/modules/firewalld_info.py
@@ -319,7 +319,6 @@ def main():
         active_zones=module.params['active_zones'],
         collected_zones=list(),
         undefined_zones=list(),
-        warnings=list(),
     )
 
     # Exit with failure message if requirements modules are not installed.
