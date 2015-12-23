--- Keyboard.h.orig	2015-10-24 12:09:14 UTC
+++ Keyboard.h
@@ -21,7 +21,7 @@
   void Process();
   void setKeymap(std::map<int,int> keymap);
   void setDbusName(std::string dbus_name);
-  void Sleep(unsigned int dwMilliSeconds);
+  int Hit();
   int getEvent();
  private:
   void restore_term();
