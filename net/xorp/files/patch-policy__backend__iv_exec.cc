--- ./policy/backend/iv_exec.cc.orig	2011-03-16 21:27:54.000000000 +0000
+++ ./policy/backend/iv_exec.cc	2014-02-26 21:17:13.000000000 +0000
@@ -275,7 +275,11 @@
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
