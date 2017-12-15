--- third_party/waf/wafadmin/Tools/cc.py.orig	2017-01-11 07:55:16 UTC
+++ third_party/waf/wafadmin/Tools/cc.py
@@ -88,7 +88,7 @@ def c_hook(self, node):
 		raise Utils.WafError('Have you forgotten to set the feature "cc" on %s?' % str(self))
 	return task
 
-cc_str = '${CC} ${CCFLAGS} ${CPPFLAGS} ${_CCINCFLAGS} ${_CCDEFFLAGS} ${CC_SRC_F}${SRC} ${CC_TGT_F}${TGT}'
+cc_str = '${CC} ${CCFLAGS} ${_CCINCFLAGS} ${CPPFLAGS} ${_CCDEFFLAGS} ${CC_SRC_F}${SRC} ${CC_TGT_F}${TGT}'
 cls = Task.simple_task_type('cc', cc_str, 'GREEN', ext_out='.o', ext_in='.c', shell=False)
 cls.scan = ccroot.scan
 cls.vars.append('CCDEPS')
