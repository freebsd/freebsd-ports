--- bonobomm/servers/control.h.orig	Tue Aug 17 21:13:56 2004
+++ bonobomm/servers/control.h	Tue Aug 17 21:14:42 2004
@@ -71,7 +71,7 @@
   typedef BonoboControlClass      BaseClassType;
 
 private:
-  friend class CppClassType;
+  friend class Control_Class;
   static CppClassType control_class_;
 
   Control(const Control&);
