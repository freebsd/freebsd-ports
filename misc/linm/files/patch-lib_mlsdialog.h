In file included from mlsdialog.cpp:1:
./mlsdialog.h:30:10: error: cannot initialize return object of type 'void *' with an rvalue of type 'bool'
                return false;
                       ^~~~~

--- lib/mlsdialog.h.orig	2018-08-30 11:11:28 UTC
+++ lib/mlsdialog.h
@@ -27,7 +27,7 @@ class MlsDialog (public)
 	virtual void*	MsgWaitBox(const string& sTitle, const string& sMsg)
 	{
 		cout << "MsgWaitBox :: " << sTitle << "Msg :: " << sMsg << endl;
-		return false;
+		return NULL;
 	}
 	virtual void	MsgWaitEnd(void* ) {}
 	virtual int		InputBox(const string& sTitle, string& sInputStr, bool /*bPasswd*/ = false)
