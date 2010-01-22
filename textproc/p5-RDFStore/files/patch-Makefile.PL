--- Makefile.PL.orig	2006-06-19 19:10:21.000000000 +0900
+++ Makefile.PL	2010-01-22 12:28:28.161357031 +0900
@@ -816,9 +816,6 @@
 		};
 	};
 
-# build client libdbms library first
-`(cd dbms/libdbms; make clean; make)`;
-
 
 WriteMakefile(
 	#DIR	=> [ 'RDFNode' ],
@@ -839,6 +836,11 @@
                            ) : ()
 );
 
+# build client libdbms library first
+chomp(my $_CCCDLFLAGS=`make -VCCCDLFLAGS`);
+chomp(my $_CFLAGS=`make -VCFLAGS`);
+print `cd dbms/libdbms; make clean; make CFLAGS="${_CFLAGS} ${_CCCDLFLAGS}"`;
+
 sub MY::post_initialize {
 	print <<EOT;
 
