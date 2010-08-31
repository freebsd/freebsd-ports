
$FreeBSD$

--- fsdump/freebsd-lib.pl.orig
+++ fsdump/freebsd-lib.pl
@@ -195,10 +195,12 @@
 	$cmd .= " -M" if ($_[0]->{'multi'});
 	$cmd .= " -h" if ($_[0]->{'links'});
 	$cmd .= " -l" if ($_[0]->{'xdev'});
+	if (${tar_command} ne '/usr/bin/tar') {
 	$cmd .= " -F \"$tapecmd $_[0]->{'id'}\""
 		if (!$_[0]->{'gzip'});
 	$cmd .= " --rsh-command=$_[0]->{'rsh'}"
 		if ($_[0]->{'rsh'} && $_[0]->{'host'});
+	}
 	$cmd .= " $_[0]->{'extra'}" if ($_[0]->{'extra'});
 	$cmd .= " '$_[0]->{'dir'}'";
 	}
