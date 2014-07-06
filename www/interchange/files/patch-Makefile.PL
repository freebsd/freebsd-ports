From: René Hertell <interchange@hertell.com>
Date: Wed, 24 Jun 2009 15:28:50 +0000 (+0300)
Subject: Fixed Makefile.PL to honour the DESTDIR-variable when doing eg. "make DESTDIR=/tmp... 
X-Git-Tag: REL_5_7_2~51
X-Git-Url: http://git.icdevgroup.org/?p=interchange.git;a=commitdiff_plain;h=837be0427f40fd8f2d34fc3d6bbdc4d84aeb4ad3

Fixed Makefile.PL to honour the DESTDIR-variable when doing eg. "make DESTDIR=/tmp/pacage install"
---

diff --git a/Makefile.PL b/Makefile.PL
index ec81b8c..b26c529 100644
--- Makefile.PL
+++ Makefile.PL
@@ -739,7 +739,7 @@ sub MY::install {
 		next unless $MV::Default{$_};
 		push @args, "$_=$MV::Default{$_}";
 	}
-	push @args, 'final=$(INSTALLARCHLIB)';
+	push @args, 'final=$(DESTDIR)$(INSTALLARCHLIB)';
 
 	my $argstring = join " ", @args;
 
