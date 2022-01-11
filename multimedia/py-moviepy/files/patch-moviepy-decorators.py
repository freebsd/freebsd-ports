Obtained from:	https://github.com/Zulko/moviepy/commit/2947e4a036513a264de3fc5234160e71d1b06aed

--- moviepy/decorators.py.orig	2020-05-07 15:34:11 UTC
+++ moviepy/decorators.py
@@ -3,6 +3,7 @@ all decorators used in moviepy go there
 """
 
 import decorator
+import inspect
 
 from moviepy.tools import cvsecs
 
@@ -76,12 +77,7 @@ def preprocess_args(fun,varnames):
     """ Applies fun to variables in varnames before launching the function """
     
     def wrapper(f, *a, **kw):
-        if hasattr(f, "func_code"):
-            func_code = f.func_code # Python 2
-        else:
-            func_code = f.__code__ # Python 3
-            
-        names = func_code.co_varnames
+        names = inspect.getfullargspec(func).args
         new_a = [fun(arg) if (name in varnames) else arg
                  for (arg, name) in zip(a, names)]
         new_kw = {k: fun(v) if k in varnames else v
@@ -120,12 +116,7 @@ def use_clip_fps_by_default(f, clip, *a, **k):
                 " the clip's fps with `clip.fps=24`" % f.__name__)
 
 
-    if hasattr(f, "func_code"):
-        func_code = f.func_code # Python 2
-    else:
-        func_code = f.__code__ # Python 3
-        
-    names = func_code.co_varnames[1:]
+    names = inspect.getfullargspec(func).args[1:]
     
     new_a = [fun(arg) if (name=='fps') else arg
              for (arg, name) in zip(a, names)]
