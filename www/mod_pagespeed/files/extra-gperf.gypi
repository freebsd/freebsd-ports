--- net/instaweb/gperf.gypi.orig	2012-02-06 20:45:36.000000000 -0500
+++ net/instaweb/gperf.gypi	2012-02-06 20:45:58.000000000 -0500
@@ -23,12 +23,13 @@
       'message': 'Generating C++ code from <(RULE_INPUT_PATH)',
       'variables': {
         'gperf_out_dir': '<(SHARED_INTERMEDIATE_DIR)/gperf_out/instaweb',
+        'gperf_bin_dir': '%%LOCALBASE%%/bin',
       },
       'outputs': [
         '<(gperf_out_dir)/<(instaweb_gperf_subdir)/<(RULE_INPUT_ROOT).gp.cc',
       ],
       'action': [
-        'gperf',
+        '<(gperf_bin_dir)/gperf',
         '-m 10',
         '<(instaweb_root)/<(instaweb_gperf_subdir)/<(RULE_INPUT_NAME)',
         '--output-file=<(gperf_out_dir)/<(instaweb_gperf_subdir)/<(RULE_INPUT_ROOT).gp.cc',
