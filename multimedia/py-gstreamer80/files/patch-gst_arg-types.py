--- gst/arg-types.py.orig	Fri Oct 13 12:08:08 2006
+++ gst/arg-types.py	Fri Oct 13 12:16:20 2006
@@ -49,6 +49,8 @@ class GstDataPtrArg(ArgType):
             info.add_parselist('O', ['&py_' + pname], [pname])
             info.arglist.append(pname)
             info.codebefore.append(self.normal % {'name':  pname})
+    def write_return(self, ptype, ownsreturn, info):
+        return
 
 class XmlNodeArg(ArgType):
 	"""libxml2 node generator"""
