--- tosh_hci.h.orig	Wed Mar 19 16:53:24 2003
+++ tosh_hci.h	Fri Oct  3 17:34:15 2003
@@ -80,9 +80,9 @@
                                                unsigned ecx,unsigned edx) throw();
                                                
     static unsigned hci_read(HCI_FUNCTION fn,unsigned ecx,unsigned edx) 
-                                                throw(runtime_error);
+                                                throw(std::runtime_error);
     static void hci_write(HCI_FUNCTION fn,unsigned ecx,unsigned edx) 
-                                                throw(runtime_error);                                                
+                                                throw(std::runtime_error);                                                
 protected:                        
     typedef std::pair<unsigned,std::string> VAR_INFO;
     
