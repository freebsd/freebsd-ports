###########################################################################
# This patch was contributed by Dimitry Andric.
###########################################################################
# The contents of this file are subject to the terms of the
# Common Development and Distribution License, Version 1.0 only
# (the "License").  You may not use this file except in compliance
# with the License.
#
# See the file CDDL.Schily.txt in this distribution for details.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file CDDL.Schily.txt from this distribution.
###########################################################################
# The file CDDL.Schily.txt can be found in the original cdrtools tarball,
# which is mirrored at ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/.
###########################################################################

--- inc/avoffset.c.orig	2011-11-28 19:28:41 UTC
+++ inc/avoffset.c
@@ -60,7 +60,7 @@ main(ac, av)
 {
 	int		stdir;
 #ifdef	HAVE_SCANSTACK
-	register struct frame *fp;
+	volatile struct frame *fp;
 	register int	i = 0;
 	register int	o = 0;
 
