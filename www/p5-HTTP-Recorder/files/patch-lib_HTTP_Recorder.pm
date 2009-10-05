
$FreeBSD$

--- lib/HTTP/Recorder.pm.orig
+++ lib/HTTP/Recorder.pm
@@ -344,12 +344,13 @@
     # get rid of the arguments we added
     my $prefix = $self->{prefix};
 
-    for my $key ($content->query_param) {
-	if ($key =~ /^$prefix-/) {
-	    $content->query_param_delete($key);
-	}
-    }
-    return $content;
+	$content =~ s/$prefix-(.*?)\?(.*?)&//g;
+	$content =~ s/$prefix-(.*?)&//g;
+	$content =~ s/$prefix-(.*?)$//g;
+	$content =~ s/&$//g;
+	$content =~ s/\?$//g;
+
+	return $content;
 }
 
 sub extract_values {
