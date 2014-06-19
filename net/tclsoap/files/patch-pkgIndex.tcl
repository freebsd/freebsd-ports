diff --git pkgIndex.tcl pkgIndex.tcl
index b7fb4e3..ebdf78f 100644
--- pkgIndex.tcl
+++ pkgIndex.tcl
@@ -11,8 +11,7 @@
 package ifneeded SOAP 1.6.7 [list source [file join $dir SOAP.tcl]]
 package ifneeded SOAP::CGI 1.0 [list source [file join $dir SOAP-CGI.tcl]]
 package ifneeded SOAP::Domain 1.4 [list source [file join $dir SOAP-domain.tcl]]
-package ifneeded SOAP::Service 0.4 [list source [file join $dir SOAP-service.tcl]]
-package ifneeded SOAP::Utils 1.0 [list source [file join $dir utils.tcl]]
+package ifneeded SOAP::Utils 1.0.1 [list source [file join $dir utils.tcl]]
 package ifneeded SOAP::ftp 1.0 [list source [file join $dir ftp.tcl]]
 package ifneeded SOAP::http 1.0 [list source [file join $dir http.tcl]]
 package ifneeded SOAP::https 1.0 [list source [file join $dir https.tcl]]
