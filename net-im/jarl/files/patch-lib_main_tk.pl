--- lib/main_tk.pl.orig	2008-03-12 02:55:50.000000000 +0100
+++ lib/main_tk.pl	2008-03-12 02:55:59.000000000 +0100
@@ -947,7 +947,7 @@
   $GUI{top}->deiconify();
   $GUI{top}->lower($GUI{Login}->{window}) if Exists($GUI{Login}->{window});
 
-  $GUI{Login}->{Connect}->configure(state=>"normal");
+  $GUI{Login}->{Connect}->configure(-state=>"normal");
 
   $GUI{top}->after(1500, sub { &jarlMainIF_Loop() });
 }
