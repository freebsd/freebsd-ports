--- CGI/BasePlus.pm.orig	Sat Apr  5 04:16:35 1997
+++ CGI/BasePlus.pm	Fri Apr 19 18:47:59 2002
@@ -178,7 +178,7 @@
     $bytesToRead = $self->{LENGTH} if $self->{LENGTH} < $bytesToRead;
 
     # Try to read some data.  We may hang here if the browser is screwed up.  
-    my $bytesRead = read($self->{IN},$self->{BUFFER},$bytesToRead,$bufferLength);
+    my $bytesRead = CORE::read($self->{IN},$self->{BUFFER},$bytesToRead,$bufferLength);
 
     # An apparent bug in the Netscape Commerce server causes the read()
     # to return zero bytes repeatedly without blocking if the
