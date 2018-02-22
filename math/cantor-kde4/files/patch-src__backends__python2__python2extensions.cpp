--- ./src/backends/python2/python2extensions.cpp.orig	2013-12-22 06:37:50.000000000 +0000
+++ ./src/backends/python2/python2extensions.cpp	2014-01-29 22:46:16.542974457 +0000
@@ -52,7 +52,7 @@
 QString Python2VariableManagementExtension::clearVariables()
 {
     QString delVariablesPythonSession = "for keyPythonBackend in dir():\n"                                 \
-                                        "    if (not 'PythonBackend' in keyPythonBackend)\ "               \
+                                        "    if (not 'PythonBackend' in keyPythonBackend)\\ "               \
                                         "and (not '__' in keyPythonBackend):\n"                            \
                                         "        del(globals()[keyPythonBackend])\n"                       \
                                         "del(keyPythonBackend)\n";
@@ -64,8 +64,8 @@
     QString classSavePythonSession = "import shelve\n"                                                               \
                                      "shelvePythonBackend = shelve.open('%1', 'n')\n"                                \
                                      "for keyPythonBackend in dir():\n"                                              \
-                                     "    if (not 'PythonBackend' in keyPythonBackend)\ "                            \
-                                     "and (not '__' in keyPythonBackend)\ "                                          \
+                                     "    if (not 'PythonBackend' in keyPythonBackend)\\ "                            \
+                                     "and (not '__' in keyPythonBackend)\\ "                                          \
                                      "and (not '<module ' in unicode(globals()[keyPythonBackend])):\n"               \
                                      "        shelvePythonBackend[keyPythonBackend] = globals()[keyPythonBackend]\n" \
                                      "shelvePythonBackend.close()\n"                                                 \
