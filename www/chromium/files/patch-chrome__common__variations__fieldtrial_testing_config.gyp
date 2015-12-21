--- chrome/common/variations/fieldtrial_testing_config.gyp.orig	2015-12-16 21:13:34.948159764 +0100
+++ chrome/common/variations/fieldtrial_testing_config.gyp	2015-12-16 21:14:00.477158698 +0100
@@ -19,7 +19,7 @@
       'conditions': [
         ['OS!="android"', {'sources/': [['exclude', '_android\\.json$']]}],
         ['OS!="win"', {'sources/': [['exclude', '_win\\.json$']]}],
-        ['OS!="linux" or chromeos==1', {'sources/': [['exclude', '_linux\\.json$']]}],
+        ['(OS!="linux" or chromeos==1) and os_bsd!=1', {'sources/': [['exclude', '_linux\\.json$']]}],
         ['OS!="mac"', {'sources/': [['exclude', '_mac\\.json$']]}],
         ['chromeos!=1', {'sources/': [['exclude', '_chromeos\\.json$']]}],
         ['OS!="ios"', {'sources/': [['exclude', '_ios\\.json$']]}],
