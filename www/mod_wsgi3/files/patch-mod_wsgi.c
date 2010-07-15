--- ./mod_wsgi.c.orig	2010-03-09 01:48:50.000000000 -0800
+++ ./mod_wsgi.c	2010-07-15 12:31:01.189153878 -0700
@@ -5648,6 +5648,26 @@
     module = PyImport_ImportModule("atexit");
     Py_XDECREF(module);
 
+    /*
+     * In Python 2.6.5 and Python 3.1.2 the shutdown of
+     * threading was moved back into Py_Finalize() for the main
+     * Python interpreter. Because we shutting down threading
+     * ourselves, the second call results in errors being logged
+     * when Py_Finalize() is called and the shutdown function
+     * called a second time. The errors don't indicate any real
+     * problem and the threading module ignores them anyway.
+     * Whether we are using Python with this changed behaviour
+     * can only be checked by looking at run time version.
+     * Rather than try and add a dynamic check, create a fake
+     * 'dummy_threading' module as the presence of that shuts up
+     * the messages. It doesn't matter that the rest of the
+     * shutdown function still runs as everything is already
+     * stopped so doesn't do anything.
+     */
+
+    if (!PyImport_AddModule("dummy_threading"))
+        PyErr_Clear();
+
     Py_Finalize();
 
     wsgi_python_initialized = 0;
