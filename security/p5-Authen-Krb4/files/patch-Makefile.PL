--- Makefile.PL~	Mon Jun 12 19:07:25 2000
+++ Makefile.PL	Wed Jan 31 17:04:48 2001
@@ -5,7 +5,6 @@
     'NAME'	=> 'Authen::Krb4',
     'VERSION_FROM' => 'Krb4.pm',
     # Remove '-lresolv' if you're not using KTH Kerberos libraries
-    'LIBS'	=> ['-L/usr/local/krb4/lib -lkrb -ldes -lresolv'],
+    'LIBS'	=> ['-lkrb -ldes'],
     'DEFINE'	=> '',
-    'INC'	=> '-I/usr/local/krb4/include'
 );
