$FreeBSD$

--- exceptions.h.orig	Mon Jun 30 17:27:19 2003
+++ exceptions.h	Mon Jun 30 17:29:00 2003
@@ -116,6 +116,8 @@
    // Returns true if this is a benine exception.
    bool isBenine() const;
 
+   ~XxUsageError() throw() { }
+
 private:
 
    /*----- data members -----*/
@@ -142,6 +144,7 @@
       const QString& msg = QString::null // use errno string only.
    );
 
+   ~XxIoError() throw() { }
 };
 
 /*==============================================================================
@@ -161,6 +164,8 @@
    XxInternalError( 
       XX_EXC_PARAMS_DECL(file,line)
    );
+
+   ~XxInternalError() throw() { }
 
 };
