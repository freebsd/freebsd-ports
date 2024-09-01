- submitted here: https://github.com/LostRuins/koboldcpp/issues/1110

--- koboldcpp.py.orig	2024-09-01 15:51:59 UTC
+++ koboldcpp.py
@@ -4159,8 +4159,9 @@ def main(launch_args,start_server=True):
 
 
     #load embedded lite
+    basepath = os.path.abspath(os.path.dirname(os.path.realpath(__file__)))
+
     try:
-        basepath = os.path.abspath(os.path.dirname(__file__))
         with open(os.path.join(basepath, "klite.embd"), mode='rb') as f:
             embedded_kailite = f.read()
             # patch it with extra stuff
@@ -4174,7 +4175,6 @@ def main(launch_args,start_server=True):
         print("Could not find KoboldAI Lite. Embedded KoboldAI Lite will not be available.")
 
     try:
-        basepath = os.path.abspath(os.path.dirname(__file__))
         with open(os.path.join(basepath, "kcpp_docs.embd"), mode='rb') as f:
             embedded_kcpp_docs = f.read()
             print("Embedded API docs loaded.")
@@ -4182,7 +4182,6 @@ def main(launch_args,start_server=True):
         print("Could not find Embedded KoboldCpp API docs.")
 
     try:
-        basepath = os.path.abspath(os.path.dirname(__file__))
         with open(os.path.join(basepath, "kcpp_sdui.embd"), mode='rb') as f:
             embedded_kcpp_sdui = f.read()
             if args.sdmodel:
