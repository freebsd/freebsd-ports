--- ../../../Net-RawSock-1.0/Makefile.PL	Thu Feb 21 14:05:26 2002
+++ Makefile.PL	Mon Feb  3 14:18:38 2003
@@ -1,4 +1,5 @@
- use ExtUtils::MakeMaker;
+use ExtUtils::MakeMaker;
+
 WriteMakefile(
     NAME         => 'Net::RawSock',
     DISTNAME     => 'Net-RawSock',
@@ -6,6 +7,7 @@
     LIBS         => [''],   # e.g., '-lm'
     DEFINE       => '',     # e.g., '-DHAVE_SOMETHING'
     INC          => '',     # e.g., '-I/usr/include/other'
+    PM           => {'RawSock.pm' => '$(INST_LIBDIR)/RawSock.pm'},
     dist => {
       'COMPRESS' => "gzip -9f",
       'SUFFIX'   => "gz"
