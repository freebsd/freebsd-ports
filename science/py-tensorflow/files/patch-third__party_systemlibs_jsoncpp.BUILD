--- third_party/systemlibs/jsoncpp.BUILD.orig	2019-10-14 21:08:43 UTC
+++ third_party/systemlibs/jsoncpp.BUILD
@@ -8,9 +8,7 @@ filegroup(
 HEADERS = [
     "include/json/allocator.h",
     "include/json/assertions.h",
-    "include/json/autolink.h",
     "include/json/config.h",
-    "include/json/features.h",
     "include/json/forwards.h",
     "include/json/json.h",
     "include/json/reader.h",
@@ -25,7 +23,7 @@ genrule(
     cmd = """
       for i in $(OUTS); do
         i=$${i##*/}
-        ln -sf $(INCLUDEDIR)/jsoncpp/json/$$i $(@D)/include/json/$$i
+        ln -sf $(INCLUDEDIR)/json/$$i $(@D)/include/json/$$i
       done
     """,
 )
