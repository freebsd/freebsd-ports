--- asciidoc.py	Mon Mar 30 18:37:04 2009 +1300
+++ asciidoc.py	Fri Apr 03 12:38:26 2009 +1300
@@ -3845,9 +3845,9 @@
             else:
                 sections[section] = contents
         rdr.close()
-        document.update_attributes() # So they are available immediately.
         self.load_sections(sections)
         self.loaded.append(os.path.realpath(fname))
+        document.update_attributes() # So they are available immediately.
 
     def load_sections(self,sections):
         '''Loads sections dictionary. Each dictionary entry contains a




