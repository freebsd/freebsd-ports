--- device.cpp.orig	2017-04-14 15:17:22.504454000 +0000
+++ device.cpp	2017-04-14 15:27:24.544699000 +0000
@@ -244,17 +244,17 @@ static PyObject * Device_new(PyTypeObjec
 
       if( !(self->cecVersion = Py_BuildValue("s", ver_str)) ) return NULL;
 
-      cec_osd_name name;
+      std::string name;
       Py_BEGIN_ALLOW_THREADS
       name = adapter->GetDeviceOSDName(self->addr);
       Py_END_ALLOW_THREADS
-      if( !(self->osdName = Py_BuildValue("s", name.name)) ) return NULL;
+      if( !(self->osdName = Py_BuildValue("s", name.c_str())) ) return NULL;
 
-      cec_menu_language lang;
+      std::string lang;
       Py_BEGIN_ALLOW_THREADS
-      adapter->GetDeviceMenuLanguage(self->addr, &lang);
+      lang = adapter->GetDeviceMenuLanguage(self->addr);
       Py_END_ALLOW_THREADS
-      if( !(self->lang = Py_BuildValue("s", lang.language)) ) return NULL;
+      if( !(self->lang = Py_BuildValue("s", lang.c_str())) ) return NULL;
    }
 
    return (PyObject *)self;
