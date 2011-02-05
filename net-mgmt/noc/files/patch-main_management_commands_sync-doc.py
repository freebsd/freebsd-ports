--- main/management/commands/sync-doc.py.orig	2011-01-31 16:14:43.000000000 +0600
+++ main/management/commands/sync-doc.py	2011-01-31 16:17:57.000000000 +0600
@@ -43,10 +43,6 @@ class Command(BaseCommand):
         return rewrite_when_differ(db_path,out.getvalue())
         
     def handle(self, *args, **options):
-        # Prepare paths
-        sphinx_build=os.path.abspath(os.path.join("contrib","bin","sphinx-build"))
-        if not os.path.exists(sphinx_build):
-            raise CommandError("%s not found. Please rebuild contrib/"%sphinx_build)
         #
         se_db_updated=self.update_se_db()
         # Prepare options
@@ -56,6 +52,8 @@ class Command(BaseCommand):
         # Prepare environment
         env=os.environ.copy()
         env["PYTHONPATH"]=":".join(sys.path)
+	# add path from contrib
+	env["PATH"]=os.path.abspath(os.path.join("contrib","bin"))+":"+env["PATH"]
         # Rebuild all documentation
         for conf in glob.glob("share/docs/*/*/conf.py"):
             d,f=os.path.split(conf)
@@ -69,5 +67,5 @@ class Command(BaseCommand):
                         os.makedirs(p)
                     except OSError:
                         raise CommandError("Unable to create directory: %s"%p)
-            cmd=[sphinx_build]+opts+["-b","html","-d",doctrees,"-D","latex_paper_size=a4",".",html]
+            cmd=["sphinx-build"]+opts+["-b","html","-d",doctrees,"-D","latex_paper_size=a4",".",html]
             subprocess.call(cmd,cwd=d,env=env)
