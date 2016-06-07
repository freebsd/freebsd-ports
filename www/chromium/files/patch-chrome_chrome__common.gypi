--- chrome/chrome_common.gypi.orig	2016-05-11 19:02:17 UTC
+++ chrome/chrome_common.gypi
@@ -30,8 +30,8 @@
       'common/common_param_traits.cc',
       'common/common_param_traits.h',
       'common/common_param_traits_macros.h',
-      'common/component_flash_hint_file_linux.cc',
-      'common/component_flash_hint_file_linux.h',
+#      'common/component_flash_hint_file_linux.cc',
+#      'common/component_flash_hint_file_linux.h',
       'common/content_restriction.h',
       'common/content_settings_pattern_serializer.cc',
       'common/content_settings_pattern_serializer.h',
@@ -381,7 +381,7 @@
             ['chromeos==1', {
               'sources': [ '<@(chrome_common_extensions_chromeos_sources)' ],
             }],
-            ['OS=="win" or OS=="linux"', {
+            ['OS=="win" or OS=="linux" or os_bsd==1', {
               'sources': [
                 'common/extensions/api/input_ime/input_components_handler.cc',
                 'common/extensions/api/input_ime/input_components_handler.h',
