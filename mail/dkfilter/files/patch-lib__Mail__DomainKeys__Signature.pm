--- lib/Mail/DomainKeys/Signature.pm.orig	Wed Jun 22 00:43:53 2005
+++ lib/Mail/DomainKeys/Signature.pm	Sat Jul 15 23:40:22 2006
@@ -78,14 +78,15 @@
 	$self->algorithm and
 		$text .= "a=" . $self->algorithm . "; ";
 
+	$text .= "q=" . $self->protocol . "; ";
+	$text .= "c=" . $self->method . ";\n\t";
+	$text .= "s=" . $self->selector . "; ";
+	$text .= "d=" . $self->domain . ";\n\t";
+
 	$self->headerlist and
-		$text .= "h=" . $self->headerlist . "; ";
+		$text .= "h=" . $self->headerlist . ";\n\t";
 
 	$text .= "b=" . $self->signature . "; ";
-	$text .= "c=" . $self->method . "; ";
-	$text .= "d=" . $self->domain . "; ";
-	$text .= "q=" . $self->protocol . "; ";
-	$text .= "s=" . $self->selector;
 
 	length $text and
 		return $text;
