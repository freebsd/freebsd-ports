--- inst/txi2index.m.orig	2022-04-08 22:22:07.568707000 -0500
+++ inst/txi2index.m	2022-04-08 22:22:27.662102000 -0500
@@ -86,7 +86,7 @@
       elseif (strncmpi (SECTION, line, length (SECTION)))
         section = strtrim (line (length (SECTION)+1:end));
         if (idx == 0 || !isempty (index.provides{idx}.functions))
-          idx ++;
+          idx++;
         endif
 
         index.provides{idx} = struct ();
@@ -94,7 +94,7 @@
         index.provides{idx}.functions = {};
       elseif (strncmpi (DOCSTRING, line, length (DOCSTRING)))
         if (idx == 0)
-          idx ++;
+          idx++;
 
           index.provides{idx} = struct ();
           index.provides{idx}.category = default_section;
