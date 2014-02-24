Taken from commit 6c26b50205

--- ./turpial/ui/qt/worker.py.orig	2013-12-19 01:59:58.000000000 +0000
+++ ./turpial/ui/qt/worker.py	2014-02-22 14:36:16.000000000 +0000
@@ -336,10 +336,10 @@
     # FIXME: Remove this after implement this in libturpial
     def load_account(self, account_id, trigger_signal=True):
         if trigger_signal:
-            self.register(self.core.accman.load, (account_id),
+            self.register(self.core.account_manager.load, (account_id),
                 self.__after_load_account)
         else:
-            self.core.accman.load(account_id)
+            self.core.account_manager.load(account_id)
             self.__after_load_account()
 
     def delete_account(self, account_id):
