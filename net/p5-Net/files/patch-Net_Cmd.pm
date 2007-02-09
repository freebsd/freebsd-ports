--- Net/Cmd.pm~	Fri Oct 27 13:08:07 2006
+++ Net/Cmd.pm	Fri Feb  9 16:02:10 2007
@@ -21,8 +21,6 @@
   }
 }
 
-my $doUTF8 = eval { require utf8 };
-
 $VERSION = "2.27";
 @ISA     = qw(Exporter);
 @EXPORT  = qw(CMD_INFO CMD_OK CMD_MORE CMD_REJECT CMD_ERROR CMD_PENDING);
@@ -394,8 +392,6 @@
  my $cmd = shift;
  my $arr = @_ == 1 && ref($_[0]) ? $_[0] : \@_;
  my $line = join("" ,@$arr);
-
- utf8::encode($line) if $doUTF8;
 
  return 0 unless defined(fileno($cmd));
 
