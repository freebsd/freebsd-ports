# Fixes cron.file from upstream issue #34094/#34095 [1].  This will be in
# 2016.3.2.
# https://github.com/saltstack/salt/issues/34094
# https://github.com/saltstack/salt/pull/34095
--- salt/states/cron.py.orig    2016-06-13 22:17:50 UTC
+++ salt/states/cron.py
@@ -540,6 +540,7 @@ def file(name,
             __env__,
             context,
             defaults,
+            False,        # skip_verify
             **kwargs
         )
     except Exception as exc:
@@ -573,12 +574,12 @@ def file(name,
         ret['comment'] = 'Unable to manage file: {0}'.format(exc)
         return ret
 
+    cron_ret = None
     if ret['changes']:
         cron_ret = __salt__['cron.write_cron_file_verbose'](user, cron_path)
         ret['changes'] = {'diff': ret['changes']['diff']}
         ret['comment'] = 'Crontab for user {0} was updated'.format(user)
     elif ret['result']:
-        cron_ret = None
         ret['comment'] = 'Crontab for user {0} is in the correct ' \
                          'state'.format(user)
 
