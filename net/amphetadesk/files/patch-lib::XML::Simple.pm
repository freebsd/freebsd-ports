--- lib/XML/Simple.pm.orig	Sun Oct  9 20:08:35 2005
+++ lib/XML/Simple.pm	Sun Oct  9 20:22:07 2005
@@ -880,7 +880,7 @@
     $encoded->{$ref} = $ref;
   }
   else {
-    if($named) {
+    if(($named) && ($ref) && ($self) && ($self->escape_value($ref))) {
       return(join('',
               $indent, '<', $name, '>',
 	      ($self->{opt}->{noescape} ? $ref : $self->escape_value($ref)),
@@ -888,7 +888,11 @@
 	    ));
     }
     else {
+      if ($ref) {
       return("$ref$nl");
+      } else {
+        return("$nl");
+      }
     }
   }
 
@@ -1013,10 +1017,12 @@
 
   my($data) = @_;
 
+  if (defined($data)) {
   $data =~ s/&/&amp;/sg;
   $data =~ s/</&lt;/sg;
   $data =~ s/>/&gt;/sg;
   $data =~ s/"/&quot;/sg;
+  }
 
   return($data);
 }
