--- Makefile.PL.orig	2007-12-02 10:23:04 UTC
+++ Makefile.PL
@@ -23,6 +23,7 @@
 } else {
     $options{CCFLAGS} = '-Wall' if $Config{cc} eq 'gcc' and $] >= 5.006;
     $options{LIBS}    = '-lpcap';
+    $options{DEFINE}  = '-DHAVE_PCAP_LIST_DATALINKS';
 }
 
 for my $arg (@ARGV) {
