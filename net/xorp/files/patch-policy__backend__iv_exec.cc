--- policy/backend/iv_exec.cc.orig	2012-01-11 17:56:10 UTC
+++ policy/backend/iv_exec.cc
@@ -275,7 +275,11 @@ void 
 IvExec::visit(Store& s)
 {
     if (_stackptr < _stack)
-	xorp_throw(RuntimeError, "Stack empty on assign of " + s.var());
+	// xorp_throw(RuntimeError, "Stack empty on assign of " + s.var());
+	{ char *tmpstr;
+	  asprintf(&tmpstr, "Stack empty on assign of %d", s.var());
+	  xorp_throw(RuntimeError, tmpstr);
+	}
 
     const Element* arg = *_stackptr;
     _stackptr--;
