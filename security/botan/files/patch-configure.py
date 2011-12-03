--- configure.py.orig	2011-10-24 19:51:31.000000000 +0000
+++ configure.py	2011-10-24 19:52:25.000000000 +0000
@@ -58,7 +58,7 @@
         self.include_dir = os.path.join(self.build_dir, 'include')
         self.full_include_dir = os.path.join(self.include_dir, 'botan')
 
-        all_files = sum([mod.add for mod in modules], [])
+        all_files = sum([list(mod.add) for mod in modules], [])
 
         self.headers = sorted(
             [file for file in all_files if file.endswith('.h')])
@@ -290,7 +290,7 @@
 
     for group in allowed_groups:
         to_obj.__dict__[group] = []
-    for (key,val) in name_val_pairs.iteritems():
+    for (key,val) in list(name_val_pairs.items()):
         to_obj.__dict__[key] = val
 
     def lexed_tokens(): # Convert to an interator
@@ -320,7 +320,7 @@
                     raise LexerError('Group "%s" not terminated' % (group),
                                      lexer.lineno)
 
-        elif token in name_val_pairs.keys():
+        elif token in list(name_val_pairs.keys()):
             to_obj.__dict__[token] = lexer.get_token()
         else: # No match -> error
             raise LexerError('Bad token "%s"' % (token), lexer.lineno)
@@ -329,7 +329,7 @@
 Convert a lex'ed map (from build-data files) from a list to a dict
 """
 def force_to_dict(l):
-    return dict(zip(l[::3],l[2::3]))
+    return dict(list(zip(l[::3],l[2::3])))
 
 """
 Represents the information about a particular module
@@ -361,7 +361,7 @@
             return os.path.join(os.path.split(self.lives_in)[0],
                                 *filename.split(':'))
 
-        self.add = map(add_dir_name, self.add)
+        self.add = list(map(add_dir_name, self.add))
 
         self.mp_bits = int(self.mp_bits)
 
@@ -413,8 +413,8 @@
             self.unaligned_ok = 0
 
     def all_submodels(self):
-        return sorted(zip(self.submodels, self.submodels) +
-                          self.submodel_aliases.items(),
+        return sorted([(k,k) for k in self.submodels] +
+                      [k for k in list(self.submodel_aliases.items())],
                       key = lambda k: len(k[0]), reverse = True)
 
     def defines(self, target_submodel, with_endian):
@@ -574,13 +574,26 @@
                 for feat in self.target_features]
 
 def canon_processor(archinfo, proc):
-    for ainfo in archinfo.values():
+    # First, try to search for an exact match
+    for ainfo in list(archinfo.values()):
         if ainfo.basename == proc or proc in ainfo.aliases:
             return (ainfo.basename, ainfo.basename)
-        else:
-            for (match,submodel) in ainfo.all_submodels():
-                if re.search(match, proc) != None:
-                    return (ainfo.basename, submodel)
+
+        for (match,submodel) in ainfo.all_submodels():
+            if proc == submodel:
+                return (ainfo.basename, submodel)
+
+    # Now, try searching via regex match
+    for ainfo in list(archinfo.values()):
+        for (match,submodel) in ainfo.all_submodels():
+            if re.search(match, proc) != None:
+                return (ainfo.basename, submodel)
+
+    logging.debug('Known CPU names: ' + ' '.join(
+        sorted(sum([[ainfo.basename] + \
+                    ainfo.aliases + \
+                    [x for (x,_) in ainfo.all_submodels()]
+                    for ainfo in list(archinfo.values())], []))))
 
     raise Exception('Unknown or unidentifiable processor "%s"' % (proc))
 
@@ -597,7 +610,7 @@
     if full_proc == '':
         full_proc = base_proc
 
-    for ainfo in archinfo.values():
+    for ainfo in list(archinfo.values()):
         if ainfo.basename == base_proc or base_proc in ainfo.aliases:
             for (match,submodel) in ainfo.all_submodels():
                 if re.search(match, full_proc) != None:
@@ -626,7 +639,7 @@
     try:
         template = PercentSignTemplate(slurp_file(template_file))
         return template.substitute(variables)
-    except KeyError, e:
+    except KeyError as e:
         raise Exception('Unbound var %s in template %s' % (e, template_file))
 
 """
@@ -642,7 +655,7 @@
     def link_to():
         libs = set()
         for module in modules:
-            for (osname,link_to) in module.libs.iteritems():
+            for (osname,link_to) in list(module.libs.items()):
                 if osname == 'all' or osname == osinfo.basename:
                     libs.add(link_to)
                 else:
@@ -798,8 +811,7 @@
 
         'doc_files': makefile_list(build_config.doc_files()),
 
-        'mod_list': '\n'.join(['%s (%s)' % (m.basename, m.realname)
-                               for m in sorted(modules)]),
+        'mod_list': '\n'.join(sorted([m.basename for m in modules])),
         }
 
 """
@@ -814,7 +826,7 @@
     def cannot_use_because(mod, reason):
         not_using_because.setdefault(reason, []).append(mod)
 
-    for (modname, module) in modules.iteritems():
+    for (modname, module) in list(modules.items()):
         if modname in options.disabled_modules:
             cannot_use_because(modname, 'disabled by user')
         elif modname in options.enabled_modules:
@@ -862,8 +874,7 @@
     while dependency_failure:
         dependency_failure = False
         for modname in to_load:
-            for deplist in map(lambda s: s.split('|'),
-                               modules[modname].dependencies()):
+            for deplist in [s.split('|') for s in modules[modname].dependencies()]:
 
                 dep_met = False
                 for mod in deplist:
@@ -1020,7 +1031,7 @@
     # First delete the build tree, if existing
     try:
         shutil.rmtree(build_config.build_dir)
-    except OSError, e:
+    except OSError as e:
         logging.debug('Error while removing build dir: %s' % (e))
 
     for dirs in [build_config.checkobj_dir,
@@ -1055,7 +1066,7 @@
             sink = os.path.join(build_config.build_dir, sink)
         templates_to_proc[source] = sink
 
-    for (template, sink) in templates_to_proc.items():
+    for (template, sink) in list(templates_to_proc.items()):
         try:
             f = open(sink, 'w')
             f.write(process_template(template, template_vars))
@@ -1128,7 +1139,7 @@
     if options.os not in osinfo:
 
         def find_canonical_os_name(os):
-            for (name, info) in osinfo.items():
+            for (name, info) in list(osinfo.items()):
                 if os in info.aliases:
                     return name
             return os # not found
@@ -1166,13 +1177,13 @@
                 matching_version = '(4\.[01234]\.)|(3\.[34]\.)|(2\.95\.[0-4])'
 
                 gcc_version = ''.join(
-                    subprocess.Popen(['g++', '-v'],
+                    str(subprocess.Popen(['g++', '-v'],
                                      stdout=subprocess.PIPE,
-                                     stderr=subprocess.PIPE).communicate())
+                                     stderr=subprocess.PIPE).communicate()))
 
                 if re.search(matching_version, gcc_version):
                     options.dumb_gcc = True
-            except OSError, e:
+            except OSError as e:
                 logging.info('Could not execute GCC for version check')
 
         if options.dumb_gcc is True:
@@ -1206,8 +1217,8 @@
 if __name__ == '__main__':
     try:
         main()
-    except Exception, e:
-        print >>sys.stderr, e
+    except Exception as e:
+        logging.error(str(e))
         #import traceback
         #traceback.print_exc(file=sys.stderr)
         sys.exit(1)
